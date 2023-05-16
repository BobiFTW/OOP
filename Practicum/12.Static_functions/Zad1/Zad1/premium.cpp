#include "premium.hpp"
#include "user.hpp"

Premium::Premium(const std::string& username, const std::string& password, const std::string& planDesc, const std::string& dateList) {
	this->planDesc = planDesc;
	this->dateList = dateList;
}
