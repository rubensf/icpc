#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

const char* bmail = "bmail.com";
const char* at = "@";

void to_lower(char* address) {
  while (*address != '\0') {
    if (*address >= 'A' && *address <= 'Z')
      *address = (*address) + 'a' - 'A';
    address++;
  }
}

void strip_dot_plus(char* address) {
  char* orig_address = address;
  char new_address[105];
  int j = 0;
  bool skipped = false;

  while (*address != '\0') {
    if (*address == '+')
      address = strstr(address, at);
    if (*address == '@')
      skipped = true;
    if (*address != '.' || (*address == '.' && skipped))
      new_address[j++] = *address;

    address++;
  }
  new_address[j] = '\0';

  strcpy(orig_address, new_address);
}

bool is_bmail(char* address) {
  char* domain = strstr(address, at) + 1;
  return strcmp(domain, bmail) == 0;
}

int main() {
  map< string, vector<string> > answers;
  map<string, vector<string> >::iterator it;
  int n;

  scanf(" %d", &n);

  for (int i = 0; i < n; i++) {
    char address[105], cpy_address[105];
    scanf(" %s", address);

    strcpy(cpy_address, address);

    to_lower(address);
    if (is_bmail(address))
      strip_dot_plus(address);

    it = answers.find(address);

    if (it != answers.end()) {
      (it->second).push_back(cpy_address);
    } else {
      vector<string> new_thing;
      new_thing.push_back(cpy_address);
      answers[address] = new_thing;
    }
  }

  printf("%lu\n", answers.size());
  for (it = answers.begin(); it != answers.end(); it++) {
    vector<string> new_thing = it->second;
    printf("%lu ", new_thing.size());
    for (int i = 0; i < new_thing.size() - 1; i++) {
      printf("%s ", new_thing[i].c_str());
    }
    printf("%s\n", new_thing[new_thing.size() - 1].c_str());
  }
}
