#include "index.h"

using namespace std;
using namespace System;
using namespace System::Windows::Forms;

int main() {

	Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
	
    myOpenCV30::MyIndex form;
    Application::Run(%form);

	return 0;
}
