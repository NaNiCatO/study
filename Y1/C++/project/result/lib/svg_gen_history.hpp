#ifndef GRAPHGEN_HISTORY_HPP
#define GRAPHGEN_HISTORY_HPP

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <limits>
#include <algorithm>



class History_GraphRenderer {
public:
    History_GraphRenderer(const std::vector<std::pair<double, double>>& data, const std::string& filename = "History_graph.svg")
        : data(data), filename(filename), barWidth(60), barSpacing(40), xOffset(50), yOffset(50), yAxisStart(0.0) {}

    void render(int svgWidth, int svgHeight) {
        calculateDimensions();
        std::ofstream file(filename);
        if (file.is_open()) {
            writeSvgHeader(file, svgWidth, svgHeight);
            drawGridLines(file);

            int x = xOffset;
            for (const auto& [start, end] : data) {
                std::vector<double> values = { start, end };
                drawSingleBar(file, std::to_string(start), values, x, "color");
                x += barWidth + barSpacing;
            }

            writeSvgFooter(file);
            file.close();
            std::cout << "Graph generated successfully: " << filename << std::endl;
        } else {
            std::cerr << "Unable to open file: " << filename << std::endl;
        }
    }

private:
    std::vector<std::pair<double, double>> data;
    std::string filename;
    double minValue;
    double maxValue;
    int gridLines;
    double gridLineValue;
    int barWidth;
    int barSpacing;
    int xOffset;
    int yOffset;
    double yAxisStart;

    void calculateDimensions() {
        minValue = 0;
        maxValue = std::numeric_limits<double>::min();

        for (const auto& [start, end] : data) {
            minValue = std::min(minValue, std::abs(start));
            minValue = std::min(minValue, std::abs(end));
            maxValue = std::max(maxValue, std::abs(start));
            maxValue = std::max(maxValue, std::abs(end));
        }

        gridLines = 5;
        gridLineValue = maxValue / gridLines;

        // Set the yAxisStart to the minimum value
        yAxisStart = minValue;
    }

    void writeSvgHeader(std::ofstream& file, int svgWidth, int svgHeight) {
        file << "<svg xmlns='http://www.w3.org/2000/svg' width='" << svgWidth << "' height='" << svgHeight << "'>\n";
    }

    void drawGridLines(std::ofstream& file) {
        int graphNumber = 1;  // Start graphNumber from 1
        int dataIndex = 0;   // Track the current index of data vector
        double totalDeposit = 0.0;
        double totalWithdraw = 0.0;
        std::vector<double> depositValues;  // Vector to store deposit values with '+'

    auto deposit = [&](double depositAmount) {
        if (depositAmount >= 0) {
            totalDeposit += depositAmount;
            depositValues.push_back(depositAmount);
        }
    };

    auto withdraw = [&](double amount) {
        if (amount < 0) {
            totalWithdraw -= -amount;
        }
    };

        for (const auto& entry : data) {
            double depositAmount = entry.first;
            double withdrawAmount = entry.first;
            deposit(depositAmount);
            withdraw(withdrawAmount);
        }

        for (int i = 0; i <= gridLines; ++i) {
            int y = yOffset + static_cast<int>((static_cast<double>(i) / gridLines) * (fileHeight() - 2 * yOffset));

            file << "<line x1='" << xOffset << "' y1='" << y << "' x2='" << (fileWidth() - xOffset) << "' y2='" << y
                 << "' stroke='lightgray' stroke-dasharray='2' />\n";  // each gridline

            int x = xOffset;
            for (int j = 1; j <= data.size(); ++j) {
                const auto& [start, end] = data[dataIndex];
                std::vector<double> values = { start - yAxisStart, end - yAxisStart };
                double barValue = values.back();
                int barY = yOffset + static_cast<int>((maxValue - barValue) / (maxValue - minValue) * (fileHeight() - 2 * yOffset));
                std::string barLabel = (start >= 0) ? "+" : "-";
                drawSingleBar(file, barLabel, values, x, "color");
                x += barWidth + barSpacing;

                dataIndex = (dataIndex + 1) % data.size();  // Move to the next index in a circular manner
            }

            if (i == 0) {
                x = xOffset;
                for (int j = 1; j <= data.size(); ++j) {
                    file << "<text x='" << (x + barWidth / 2) << "' y='" << (fileHeight() - yOffset + 15)
                         << "' text-anchor='middle'>" << graphNumber << "</text>\n";
                    x += barWidth + barSpacing;
                    graphNumber++;
                }
            }

            file << "<text x='" << (xOffset - 10) << "' y='" << (y + 5) << "' text-anchor='end' font-size='14'>"
                 << static_cast<int>(maxValue - i * gridLineValue) << "</text>\n";  // vertical information
        }

        double lastValue = data.back().second;  // Get last value from data vector

        file << "<text x='" << (xOffset + barWidth / 2) << "' y='" << (fileHeight() - yOffset + 60)
             << "' text-anchor='middle' font-size='14'>Total Amount: $" << lastValue << "</text>\n";
        file << "<text x='" << (xOffset + barWidth / 2) << "' y='" << (fileHeight() - yOffset + 100)
             << "' text-anchor='middle' font-size='14'>Total withdraw: $" << totalWithdraw << "</text>\n";

        file << "<text x='" << (xOffset + barWidth / 2) << "' y='" << (fileHeight() - yOffset + 120)
            << "' text-anchor='middle' font-size='14'>Total deposit: $" << "+" << totalDeposit << "</text>\n";

    }

    void drawSingleBar(std::ofstream& file, const std::string& label, const std::vector<double>& values, int x, const std::string& color) {
        if (values[0] != 0) {
            int startYOffset = yOffset + static_cast<int>((maxValue - std::abs(values[0])) / (maxValue - minValue) * (fileHeight() - 2 * yOffset));
            int endYOffset = yOffset + static_cast<int>((maxValue - 0) / (maxValue - minValue) * (fileHeight() - 2 * yOffset));

            int barHeight = endYOffset - startYOffset;

            std::string barColor;
            if (values[0] >= 0) {
                barColor = "#83c5be";  // Deposit bar color
            } else {
                barColor = "#e56b6f";    // Withdraw bar color
            }

            file << "<rect x='" << x << "' y='" << startYOffset << "' width='" << barWidth << "' height='"
                 << barHeight << "' fill='" << barColor << "' />\n";

            // file << "<text x='" << (x + barWidth / 2) << "' y='" << (endYOffset + 20)
            //      << "' text-anchor='middle'>" << label << "</text>\n";  //display value of withdraw or

            // Display the value above the bar, ignore the '-' value for withdraw
            if (values[0] >= 0) {
                file << "<text x='" << (x + barWidth / 2) << "' y='" << (startYOffset - 5)
                     << "' text-anchor='middle'>" << values[0] << "</text>\n";
            } else {
                file << "<text x='" << (x + barWidth / 2) << "' y='" << (startYOffset - 5)
                     << "' text-anchor='middle'>" << std::abs(values[0]) << "</text>\n";
            }
        }
    }

    void writeSvgFooter(std::ofstream& file) {
        file << "</svg>\n";
    }

    int fileWidth() const {
        return data.size() * (barWidth + barSpacing) + (2 * xOffset);
    }

    int fileHeight() const {
        return 700; // Adjust the whole scale of the graph
    }
};

std::vector<std::string> splitString(const std::string& line, char delimiter) {
    std::vector<std::string> tokens;
    std::istringstream iss(line);
    std::string token;
    while (std::getline(iss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void generate_history_graph(const std::string& path_input,  const std::string& path_output) {
    std::vector<std::pair<double, double>> depositData;
    std::ifstream file(path_input);

    if (file.is_open()) {
        std::string line;
        if (std::getline(file, line)) {
            std::vector<std::string> tokens = splitString(line, ',');
            if (tokens.size() >= 3) {
                double start = (tokens[1][0] == '+') ? std::stod(tokens[1].substr(1)) : std::stod(tokens[1]);
                double end = (tokens[2][0] == '+') ? std::stod(tokens[2].substr(1)) : std::stod(tokens[2]);
                depositData.emplace_back(start, end);
            } else {
                //std::cerr << "Invalid data format in line: " << line << std::endl;
            }
        }
        while (std::getline(file, line)) {
            std::vector<std::string> tokens = splitString(line, ',');
            if (tokens.size() > 1) {
                double start = (tokens[0][0] == '+') ? std::stod(tokens[0].substr(1)) : std::stod(tokens[0]);
                double end = (tokens[1][0] == '+') ? std::stod(tokens[1].substr(1)) : std::stod(tokens[1]);
                depositData.emplace_back(start, end);
            }
        }
        file.close();

        if (!depositData.empty()) {
            History_GraphRenderer renderer(depositData, path_output);
            renderer.render(10000, 800);
        } else {
            std::cerr << "No valid data found in the input file." << std::endl;
        }
    } else {
        std::cerr << "Unable to open file: User_data.csv" << std::endl;
    }
}

#endif