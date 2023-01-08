#include "SLlistValues.h"

int main()
{
	CListData ListObj;

	ListObj.AddValuesToListAtFront("Jaggu", 34);
	ListObj.AddValuesToListAtFront("Veer", 29);
	ListObj.AddValuesToListAtFront("dude", 5);
	ListObj.AddValuesToListAtFront("prince", 1);

	ListObj.AddValuesToListAtheEnd("anger", 62);
	ListObj.AddValuesToListAtheEnd("lovely", 60);

	ListObj.AddvaluesAtSpecificPosition("initial", 1, 5);

	ListObj.clearlist();

	return 0;


}