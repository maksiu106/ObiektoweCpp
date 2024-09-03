#ifndef FAB_KOL_H_
#define FAB_KOL_H_

#include <string>

struct DefaultPolicy {
    Kolor nieznanyKolor(const std::string& nazwa) {
    	throw std::invalid_argument("Nieznany kolor: " + nazwa);
    }
};

template<class Policy = DefaultPolicy>
struct FabrykaKolorow {
	Policy policy;
public:
	Kolor zwrocKolor(const std::string& kolor) {
		//if (kolor == "zielony" || kolor == "green") return Kolor(0,255,0);
		//else if (kolor == "czarny" || kolor == "black") return Kolor(0,0,0);
		return policy.nieznanyKolor(kolor);
	}
};
#endif /* FAB_KOL_H_ */
