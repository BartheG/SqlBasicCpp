#ifndef REQUESTBUILDER_HPP_
	#define REQUESTBUILDER_HPP_

#include <string>
#include <map>
#include <functional>

enum RequestType {
	INSERT,
	SELECT
};

class RequestBuilder {
	public:
		RequestBuilder(const std::map<std::string,std::string> &param, RequestType type, const std::string &tableName = "");
		~RequestBuilder();
		void buildRequest();
		std::string getFinalRequest() const { return this->_finalRequest; };
	private:
		void buildInsertRequest();
		void buildSelectRequest();
		std::string formatWithQuote(const std::string &toFormat);
		std::string formatAsChar(const std::string &toFormat);

		std::map<std::string,std::string> _param;
		std::map<RequestType, std::function<void(void)>> _selectRequest;
		std::string _tableName;
		std::string _finalRequest;
		RequestType _type;
};

#endif /* !REQUESTBUILDER_HPP_ */
