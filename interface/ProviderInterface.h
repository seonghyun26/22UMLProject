#ifndef PROVIDER_UI
#define PROVIDER_UI

#include <vector>
#include <string>

using namespace std;

class ProviderInterface
{
public:
  vector<string> getProviderFunctionList() { return providerFunction; }
  bool executeProviderFunction(int funcNum);
  bool provideSensor();

protected:
  vector<string> providerFunction = {"Provide Sensor", "Give Reward"};
};

#endif