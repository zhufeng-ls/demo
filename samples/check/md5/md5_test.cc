#include "md5.hpp"

using namespace websocketpp::md5;
int main()
{
    md5_state_t state;
    md5_init(&state);

    char *ss = "this is a test";
    md5_append(&state, (const unsigned char *)ss, strlen(ss));
    unsigned char result[17] = {0};
    md5_finish(&state, (unsigned char *)result);
    for (int i=0; i<16; i++)
    {
        printf("%x%x", (result[i]>>4)&(char)0x0f, result[i]&(char)0x0f);
    }
    printf("\n");
    for (int i=0; i<16; i++)
    {
        printf("%02x",  result[i]);
    }
    printf("\n");
}