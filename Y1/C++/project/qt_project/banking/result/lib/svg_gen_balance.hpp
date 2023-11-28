#ifndef GRAPHGEN_BALANCE_HPP
#define GRAPHGEN_BALANCE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <map>
#include <limits>
#include "svg_gen_history.hpp"


class Balance_GraphRenderer {
public:
    Balance_GraphRenderer(const std::vector<std::pair<double, double>>& data, const std::string& filename = "Balance_graph.svg")
        : data(data), filename(filename), barWidth(60), barSpacing(40), xOffset(50), yOffset(50), yAxisStart(0.0) {}

    void render(int svgWidth, int svgHeight) {
        calculateDimensions();
        std::ofstream file(filename);
        if (file.is_open()) {
            writeSvgHeader(file, svgWidth, svgHeight);
            drawGridLines(file);

            int x = xOffset;
            int graphNumber = 1;  // Start graphNumber from 1
            for (const auto& [start, end] : data) {
                std::vector<double> values = { start - yAxisStart, end - yAxisStart };
                drawBars(file, std::to_string(start), values, x);
                x += barWidth + barSpacing;
                graphNumber++;
            }

            writeSvgFooter(file);
            file.close();
            std::cout << "Graphs generated successfully: " << filename << std::endl;
        } else {
            std::cerr << "Unable to open file: " << filename << std::endl;
        }
    }

private:
    const std::vector<std::pair<double, double>>& data;
    const std::string& filename;
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
        minValue = std::numeric_limits<double>::max();
        maxValue = std::numeric_limits<double>::min();

        for (const auto& [start, end] : data) {
            minValue = std::min(minValue, start);
            minValue = std::min(minValue, end);
            maxValue = std::max(maxValue, start);
            maxValue = std::max(maxValue, end);
        }

        gridLines = 5;
        gridLineValue = maxValue / gridLines;

        if (minValue > 0) {
            gridLines += 1;
            minValue = 0;
        }
    }

    void writeSvgHeader(std::ofstream& file, int svgWidth, int svgHeight) {
        file << "<svg xmlns='http://www.w3.org/2000/svg' width='" << svgWidth << "' height='" << svgHeight << "'>\n";
    }

    void drawBars(std::ofstream& file, const std::string& label, const std::vector<double>& values, int x) {
        double minValue = std::min(0.0, minValue);  // Consider negative values in the range

        int y = yOffset + static_cast<int>((maxValue - values.back()) / (maxValue - minValue) * (fileHeight() - 2 * yOffset));
        int barHeight = static_cast<int>((std::abs(values.back() - minValue) / (maxValue - minValue)) * (fileHeight() - 2 * yOffset));

        file << "<rect x='" << x << "' y='" << y << "' width='" << barWidth << "' height='" << barHeight << "' fill='steelblue' />\n";
        file << "<text x='" << (x + barWidth / 2) << "' y='" << (y - 10) << "' text-anchor='middle'>" << values.back() << "</text>\n";
    }


void drawGridLines(std::ofstream& file) { 
    int graphNumber = 1;  // Start graphNumber from 1
    for (int i = 0; i <= gridLines; ++i) {
        int y = yOffset + static_cast<int>((static_cast<double>(i) / gridLines) * (fileHeight() - 2 * yOffset));

        file << "<line x1='" << xOffset << "' y1='" << y << "' x2='" << (fileWidth() - xOffset) << "' y2='" << y
             << "' stroke='lightgray' stroke-dasharray='2' />\n";  // each gridline

        int x = xOffset;
        for (const auto& [start, end] : data) {
            std::vector<double> values = { start - yAxisStart, end - yAxisStart };
            double barValue = values.back();
            int barY = yOffset + static_cast<int>((maxValue - barValue) / (maxValue - minValue) * (fileHeight() - 2 * yOffset));
            drawBars(file, "", values, x); // Call drawBars function to add label to each bar
            x += barWidth + barSpacing;
        }
        //  graph numbers when drawing the first grid line
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


void generate_balance_graph(const std::string& path_input,  const std::string& path_output) {
    std::vector<std::pair<double, double>> data;
    std::ifstream file(path_input);  // Change CSV file

    if (file.is_open()) {
        // Skip the first line
        std::string line;
        std::getline(file, line);

        while (std::getline(file, line)) {
            std::vector<std::string> tokens = splitString(line, ',');
            if (tokens.size() > 1) {
                double start = std::stod(tokens[0]);
                double end = std::stod(tokens[1]);
                data.push_back({ start, end });
            }
        }
        file.close();

        int svgWidth = 100000;  // Set the desired width
        int svgHeight = 800; // Set the desired height

        Balance_GraphRenderer renderer(data,path_output);
        renderer.render(svgWidth, svgHeight);
    } else {
        std::cerr << "Unable to open file: User_data.csv" << std::endl;
    }
}


#endif