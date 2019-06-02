#define TIXML_USE_STL
#include "tinyxml.h"
#include <string>
#include <iostream>

int main()
{
	char* name = (char*)("..//TinyXml-examples-142/resources/dream.xml");
	{
		TiXmlDocument doc;

		doc.LoadFile(name);
		std::cout << "Parse is " << (doc.Error() == false) << std::endl;
		//doc.Print();
	}

	{
		TiXmlDocument doc;
		doc.LoadFile(name);

		// Structure of the XML file:
		// - Element "PLAY"      the root Element, which is the
		//                       FirstChildElement of the Document
		// - - Element "TITLE"   child of the root PLAY Element
		// - - - Text            child of the TITLE Element

		// Navigate to the title, using the convenience function,
		// with a dangerous lack of error checking.
		const char* title = doc.FirstChildElement("PLAY")->FirstChildElement("TITLE")->GetText();
		printf("Name of play (1): %s\n", title);

		// Text is just another Node to TinyXML-2. The more
		// general way to get to the XMLText:
		TiXmlText* textNode = doc.FirstChildElement("PLAY")->FirstChildElement("TITLE")->FirstChild()->ToText();
		title = textNode->Value();
		printf("Name of play (2): %s\n", title);
	}
}
