#include <iostream>
#include <string>
#include <vector>
#include <fstream>



class Writer {
    public:
    Writer(std::ostream& n): path(n) {}
    
    void write(const std::string& str) const {
        path << str;
    }
    private:
    std::ostream& path;
};


class Doc_element {
    public:
    void write_document(const Writer& w) const{write_to(w, 0);}
    
    void write_to(const Writer& w, int lv) const{
        for (int i = 0; i < lv; ++i) {
            w.write("  ");
        }
        w.write("<" + name);
        if (children_v.empty()) {
            w.write("/>\n");
        } else {
            w.write(">\n");
            for (const auto& child : children_v) {
                child.write_to(w, lv + 1);
            }
            for (int i = 0; i < lv; ++i) {
                w.write("  ");
            }
            w.write("</" + name + ">\n");
        }
    }
    
    static Doc_element text(const std::string& t) {return Doc_element(t);}
    
    explicit Doc_element(const std::string& n): name(n) {}
    Doc_element(const std::string& n, const std::vector<Doc_element>& children): name(n), children_v(children) {}
    
    private:
    std::string name;
    std::vector<Doc_element> children_v;
};


int main()
{
    auto output = Writer(std::cout);
    auto t = Doc_element::text("Text001");
    auto e = Doc_element("em", {t, Doc_element("p", {t})});
    // `e' will represent the following HTML nodes:
    // <em>Text001 <p>Text001</p> </em>
    auto tr = Doc_element(
    "tr",
    {
    Doc_element("td", {t}), Doc_element("td", {t}),
    Doc_element("td", {t})
    });
    auto tbl = Doc_element("table", {tr, tr, tr});
    /* `tbl' will represent the following HTML nodes:
    <table>
    <tr> <td>Text001</td> <td>Text001</td> <td>Text001</td> </tr>
    <tr> <td>Text001</td> <td>Text001</td> <td>Text001</td> </tr>
    <tr> <td>Text001</td> <td>Text001</td> <td>Text001</td> </tr>
    </table>
    */

    auto n_title = Doc_element::text("Page Title");
    auto title = Doc_element("title", {n_title});
    auto n_para = Doc_element::text("paragraph");
    auto para = Doc_element("p", {n_para});
    auto result = Doc_element("html", {title,para});

    tbl.write_document(output);

   return 0;
}