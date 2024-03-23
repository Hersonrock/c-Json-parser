struct objectNode;
struct arrayNode;
union anyNode;

struct objectNode *createObjectNodeChain(int n, int n2);
struct objectnode *createObjectNode(int n);
struct arrayNode *createArrayNodeChain(int n);
struct arrayNode *createArrayNode();
char *stringCreate(char *input);
