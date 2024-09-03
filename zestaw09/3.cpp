#include <iostream>
#include <memory>
#include <vector>

class Song {
	std::string artist;
	std::string title;
public:
	Song(std::string a, std::string t) : artist(a), title(t) {
		std::cout << "Konstruuję piosenkę" << std::endl;
	}
	~Song() {
		std::cout << "Destruuję piosenkę" << std::endl;
	}
	void play() {}
};

template<class T>
std::unique_ptr<T> SongFactory(std::string a, std::string t) {
	return std::make_unique<T>(a, t);
}

int main() {
	std::cout << "ETAP 1 - konstruowanie wektora i dodawanie piosenek" << std::endl;
	std::vector<std::unique_ptr<Song> > v;

	v.push_back(SongFactory<Song>("artist", "song"));
	v.push_back(SongFactory<Song>("artist2", "song2"));
	v.push_back(SongFactory<Song>("artist3", "song3"));

	std::cout << "ETAP 2 - wypisywanie piosenek" << std::endl;
	for (auto &song : v) {
		song->play();
	}

	std::cout << "ETAP 3 - piosenki wypisane, program kończony" << std::endl;
}
