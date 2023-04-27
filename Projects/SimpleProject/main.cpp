#include <UI/BaseApplication.h>

int main()
{
    BaseApplication app(L"Simple Project");
    app.runMessageLoop();
    return 0;
}