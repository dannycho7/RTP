#include <vector>

using namespace std;

// fid occurence
class Fid_Occurence
{
public:
    int fid;
    vector<int> v_pos;
    static bool compare(const Fid_Occurence &obj1, const Fid_Occurence &obj2);
};