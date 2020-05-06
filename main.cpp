#include "Item.h"
#include "Base.h"
#include <string>

int main() {
	Base base("druzyna.txt");
	Item item("Namiot", "dobry", "U Maćka");

	base.baseUpload();
	base.saveItem(item);
}