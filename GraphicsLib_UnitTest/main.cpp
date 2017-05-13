#include <ceAplication.h>

ceEngineSDK::ceAplication* g_MyApp;

int main()
{
	g_MyApp = new ceEngineSDK::ceAplication();
	g_MyApp->Run();
	return 0;
}