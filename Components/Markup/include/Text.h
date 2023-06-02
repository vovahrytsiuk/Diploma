#pragma once
#include <iostream>
class Text
{
public:
	Text() = default;
	~Text() = default;


	void setPositionVert(int info);
	int  getPositionVert();
	void setPositionGorz(int info);
	int  getPositionGorz();

	void setHeight(int info);
	int getHeight();
	void setItalic(bool info);
	bool getItalic();
	void setUnderline(bool info);
	bool getUnderline();
	void setBold(bool info);
	bool getBold();

	std::string getText();
	void setText(std::string info);

	std::string getTitle();
	void setTitle(std::string info);

private:
	int positionVert = 0;
	int positionGorz = 0;
	std::string text = "Text";


	int height = 12;
	bool italic = false;
	bool underline = false;
	bool bold = false;
	std::string title = "Arial";


};

