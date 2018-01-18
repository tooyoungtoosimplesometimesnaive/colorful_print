#include <iostream>
#include <string>

using std::string;

using std::cout;
using std::endl;

class decorator {
	public:
	decorator(): Default("\e[39m"),
		Black("\e[30m"),
		Red("\e[31m"),
		Green("\e[32m"),
		Default_bg("\e[49m"),
		Black_bg("\e[40m"),
		Red_bg("\e[41m"),
		Green_bg("\e[42m"),
 
       		BOLD("\e[1m"),
		DIM("\e[2m"),
		UNDERLINED("\e[4m"),
		BLINK("\e[5m")	{}

	string Default, Black, Red, Green;
	string Default_bg, Black_bg, Red_bg, Green_bg;
	string BOLD, DIM, UNDERLINED, BLINK;
	string decorate(string s, string format, string foreground_color, string background_color) {
		return format + foreground_color + background_color + s + format.substr(0, 2) + "2" + format.substr(2);
	}
	string decorate(string s, string foreground_color, string background_color) {
		return foreground_color + background_color + s + Default_bg + Default;
	}
	string decorate(string s, string background_color) {
		return background_color + s + Default_bg;
	}
	void draw_cloth(int w, int h, string color) {
		string s {""};
		for (int j = 0;j < h; j++) {
			s += color;
			for (int i = 0;i < w; i++)
				s +=  " ";
			s += Default_bg;
			s += "\n";
		}
		cout << s << endl;
	}
};


int main() {
//	cout << "\e[31mHello World\e[0m" << endl;
	decorator d;

//	cout << d.decorate("Test", d.UNDERLINED, d.Red, "") << endl;
	d.draw_cloth(40, 20, d.Red_bg);
	return 0;
}

