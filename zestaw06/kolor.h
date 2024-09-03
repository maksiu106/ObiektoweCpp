#ifndef KOLOR_H_
#define KOLOR_H_

struct Kolor {
	int red;
	int green;
	int blue;
	Kolor() {
		red = 0;
		green = 0;
		blue = 0;
	}

	Kolor(int r, int g, int b) {
		red = r;
		green = g;
		blue = b;
	}
};

std::ostream& operator<<(std::ostream& os, const Kolor& kolor) {
		os << "R: " << kolor.red << ", G: " << kolor.green << ", B: " << kolor.blue;
		return os;
	}

#endif /* KOLOR_H_ */
