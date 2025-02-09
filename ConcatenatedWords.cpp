#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
using namespace std;

// TLE in one case
class Solution
{
public:
    struct TrieNode
    {
        bool word_end;
        TrieNode *child[26];

        TrieNode()
        {
            word_end = false;
            for (int i = 0; i < 26; i++)
            {
                child[i] = nullptr;
            }
        }
    };
    void insert_key(TrieNode *n, string &word)
    {
        TrieNode *curr = n;
        int len = word.length();
        for (int i = 0; i < len; i++)
        {
            char ch = word[i];
            if (curr->child[ch - 'a'] == nullptr)
            {
                TrieNode *new_node = new TrieNode();
                curr->child[ch - 'a'] = new_node;
            }
            curr = curr->child[ch - 'a'];
        }
        curr->word_end = true;
    }

    int dfs(TrieNode *root, TrieNode *curr, int diverted, int index, string &s)
    {
        if (curr == nullptr)
        {
            return 0;
        }
        if (index == s.length())
        {
            if (diverted && curr->word_end)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        int ch_ind = s[index] - 'a';
        int res = 0;
        if (curr->word_end && root->child[ch_ind])
        {
            res = res | dfs(root, root->child[ch_ind], 1, index + 1, s);
        }
        if (curr->child[ch_ind])
        {
            res = res | dfs(root, curr->child[ch_ind], diverted, index + 1, s);
        }
        return res;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        vector<vector<char>> trie(26);
        int n = words.size();
        TrieNode *root = new TrieNode();
        for (int i = 0; i < n; i++)
        {
            insert_key(root, words[i]);
        }
        int count = 0;
        vector<string> ans;
        for (int i = 0; i < n; i++)
        {
            int depth = 0;
            int index = 0;
            count = dfs(root, root, depth, index, words[i]);
            if (count)
            {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};

class Solution
{
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        unordered_set<string> set;
        for (auto s : words)
        {
            set.insert(s);
        }
        int n = words.size();
        int ans = 0;
        for (int w = 1; w < words.size(); w++)
        {
            int m = words[w].length();
            string s = words[w];
            vector<int> dp(m + 1, 0);
            for (int i = 1; i <= m; i++)
            {
                for (int j = (i==m)? 1: 0; j < i && !dp[i]; j++)
                {
                    dp[i] = dp[j] && set.find(s.substr(j, i - j));
                }
            }
        }
        if(dp[m]){
            ans++;
        }
        return ans;
    }
};

int main()
{
    vector<string> v = {"rfkqyuqfjkx", "vnrtysfrzrmzl", "gfve", "qfpd", "lqdqrrcrwdnxeuo", "q", "klaitgdphcspij", "hbsfyfv", "adzpbfudkklrw", "aozmixr", "ife", "feclhbvfuk", "yeqfqojwtw", "sileeztxwjl", "ngbqqmbxqcqp", "khhqr", "dwfcayssyoqc", "omwufbdfxu", "zhift", "kczvhsybloet", "crfhpxprbsshsjxd", "ilebxwbcto", "yaxzfbjbkrxi", "imqpzwmshlpj", "ta", "hbuxhwadlpto", "eziwkmg", "ovqzgdixrpddzp", "c", "wnqwqecyjyib", "jy", "mjfqwltvzk", "tpvo", "phckcyufdqml", "lim", "lfz", "tgygdt", "nhcvpf", "fbrpzlk", "shwywshtdgmb", "bkkxcvg", "monmwvytby", "nuqhmfj", "qtg", "cwkuzyamnerp", "fmwevhwlezo", "ye", "hbrcewjxvcezi", "tiq", "tfsrptug", "iznorvonzjfea", "gama", "apwlmbzit", "s", "hzkosvn", "nberblt", "kggdgpljfisylt", "mf", "h", "bljvkypcflsaqe", "cijcyrgmqirz", "iaxakholawoydvch", "e", "gttxwpuk", "jf", "xbrtspfttota", "sngqvoijxuv", "bztvaal", "zxbshnrvbykjql", "zz", "mlvyoshiktodnsjj", "qplci", "lzqrxl", "qxru", "ygjtyzleizme", "inx", "lwhhjwsl", "endjvxjyghrveu", "phknqtsdtwxcktmw", "wsdthzmlmbhjkm", "u", "pbqurqfxgqlojmws", "mowsjvpvhznbsi", "hdkbdxqg", "ge", "pzchrgef", "ukmcowoe", "nwhpiid", "xdnnl", "n", "yjyssbsoc", "cdzcuunkrf", "uvouaghhcyvmlk", "aajpfpyljt", "jpyntsefxi", "wjute", "y", "pbcnmhf", "qmmidmvkn", "xmywegmtuno", "vuzygv", "uxtrdsdfzfssmel", "odjgdgzfmrazvnd", "a", "rdkugsbdpawxi", "ivd", "bbqeonycaegxfj", "lrfkraoheucsvpi", "eqrswgkaaaohxx", "hqjtkqaqh", "berbpmglbjipnuj", "wogwczlkyrde", "aqufowbig", "snjniegvdvotu", "ocedkt", "bbufnxorixibbd", "rzuqsyr", "qghoy", "evcuanuujszitaoa", "wsx", "glafbwzdd", "znrvjqeyqi", "npitruijvyllsi", "objltu", "ryp", "nvybsfrxtlfmp", "id", "zoolzslgd", "owijatklvjzscizr", "upmsoxftumyxifyu", "xucubv", "fctkqlroq", "zjv", "wzi", "ppvs", "mflvioemycnphfjt", "nwedtubynsb", "repgcx", "gsfomhvpmy", "kdohe", "tyycsibbeaxn", "wjkfvabn", "llkmagl", "thkglauzgkeuly", "paeurdvexqlw", "akdt", "ihmfrj", "janxk", "rqdll", "cyhbsuxnlftmjc", "yybwsjmajbwtuhkk", "ovytgaufpjl", "iwbnzhybsx", "mumbh", "jqmdabmyu", "br", "lwstjkoxbczkj", "vhsgzvwiixxaob", "fso", "qnebmfl", "ooetjiz", "lq", "msxphqdgz", "mqhoggvrvjqrp", "xbhkkfg", "zxjegsyovdrmw", "jav", "mshoj", "ax", "biztkfomz", "hujdmcyxdqteqja", "gqgsomonv", "reqqzzpw", "lihdnvud", "lznfhbaokxvce", "fhxbldylqqewdnj", "rlbskqgfvn", "lfvobeyolyy", "v", "iwh", "fpbuiujlolnjl", "gvwxljbo", "ypaotdzjxxrsc", "mwrvel", "umzpnoiei", "ogwilaswn", "yw", "egdgye", "hsrznlzrf", "mwdgxaigmxpy", "yaqgault", "dtlg", "cyvfiykmkllf", "zxqyhvizqmamj", "lvvgoifltzywueyp", "abinmy", "ppzaecvmx", "qsmzc", "iddymnl", "uskihek", "evxtehxtbthq", "jvtfzddlgch", "czohpyewf", "ufzazyxtqxcu", "brxpfymuvfvs", "xrrcfuusicc", "aqhlswbzievij", "rv", "udvmara", "upityz", "fecd", "suxteeitxtg", "dfuydrtbfypbn", "cypqodxr", "wikfuxwjht", "jrliuaifpp", "vkmxys", "wvpfyfpkvgthq", "rmajxis", "jncxgviyu", "av", "nmhskodmidaj", "lkfrimprrhen", "uip", "hstyopbvuiqc", "p", "vwduwmjpblqo", "fnxwgqtvwztje", "xwnbcuggl", "iehimvoymyjasin", "spsqiu", "flhyfac", "mqrbq", "pstsxhplrrmbeddv", "hnegtuxx", "alsyxezjwtlwmxv", "jtxytykkcku", "bhhlovgcx", "xhhivxnutkx", "had", "aysulvk", "m", "anhsyxli", "jdkgfc", "potn", "lcibpxkidmwexp", "gwoxjicdkv", "tltienw", "ngiutnuqbzi", "o", "tzlyb", "vumnwehj", "os", "np", "lhv", "uzvgyeette", "ipfvr", "lpprjjalchhhcmh", "k", "pciulccqssaqgd", "tp", "dmzdzveslyjad", "wtsbhgkd", "eouxbldsxzm", "vhtonlampljgzyve", "xhnlcrldtfthul", "xhflc", "upgei", "rlaks", "yfqvnvtnqspyjbxr", "phouoyhvls", "voibuvbhhjcdflvl", "rgorfbjrofokggaf", "dqhqats", "zchpicyuawpovm", "yzwfor", "koat", "pybf", "fhdzsbiyjld", "gznfnqydisn", "xz", "po", "tcjup", "wygsnxk", "kqlima", "fgxnuohrnhg", "publurhztntgmimc", "zuufzphd", "iucrmmmjqtcey", "wnnbq", "rghzyz", "ukjqsjbmp", "mdtrgv", "vyeikgjdnml", "kxwldnmi", "apzuhsbssaxj", "tkbkoljyodlipof", "nkq", "ktwtj", "vgmkgjwle", "t", "agylw", "vomtuy", "jbtvitkqn", "vtdxwrclpspcn", "rdrls", "yxfeoh", "upj", "myctacn", "fdnor", "ahqghzhoqprgkym", "phiuvdv", "jp", "fdgpouzjwbq", "hqoyefmugjvewhxu", "qfzwuwe", "fnsbijkeepyxry", "oja", "qthkcij", "zpmqfbmnr", "ybaibmzonzqlnmd", "svo", "gjftyfehik", "jfrfgznuaytvaegm", "aljhrx", "odjq", "ogwaxrssjxgvnka", "zaqswwofedxj", "lugpktauixp", "dc", "odknlbvxrs", "jeobu", "vqythyvzxbcgrlbg", "hwc", "erpbaxq", "ujxcxck", "rrklkb", "wlrwyuy", "zmg", "yyhga", "xwdbycdu", "htedgvsrhchox", "wr", "suhesetv", "jonqwhkwezjvjgg", "sqqyrxtjkcalswq", "hvyimhe", "pjzdkmoue", "zbphmgoxq", "lbdlcumdgixjbcq", "ztzdjqmadthtdmv", "qcagsyqggcf", "if", "jpjxcjyi", "chyicqibxdgkqtg", "iwpdklhum", "wljmg", "micmun", "npdbamofynykqv", "ijsnfkpfy", "lmq", "oyjmeqvhcrvgm", "mqopusqktdthpvz", "fz", "r", "qbsqtipq", "nxtsnason", "xbpipyhh", "topsuqomfjrd", "islif", "gbndakaq", "bwnkxnwpzeoohlx", "hrtbfnq", "fguvomeepxoffg", "mat", "dzfpfnwbfuj", "onlvy", "cwcchvsasdylb", "rxfcztzqopdi", "ybrhodjn", "oqkijy", "ncvrjo", "dphbfaal", "xgtpdtkz", "sebevsopjvciwljf", "rcumyacqdapwczen", "mabkapuoud", "pbozezeygljfftvy", "bvazmzbndl", "vl", "qiaixdtbhqvlzd", "ffjfb", "svthrfmkoxbho", "cvet", "ucgqyvopafyttrh", "lbgihet", "naiqyufxffdw", "vruh", "uz", "ukffmudygjavem", "dccamymhp", "wofwgjkykm", "fbuujzxhln", "kmm", "lzandlltowjpwsal", "fapfvrmezbsjxs", "wiw", "sc", "soqlh", "hzaplclkwl", "gcdqbcdwbwa", "gadgt", "pgowefka", "juffuguqepwnfh", "nbuinl", "cpdxf", "sox", "fq", "lfnrhgsxkhx", "xrcorfygjxpi", "mwtqjwbhgh", "loc", "fkglorkkvx", "nlzdhucvayrz", "azefobxutitrf", "rlrstkcbtikklmh", "ggk", "sbphcejuylh", "nraoenhd", "zngyodiqlchxyycx", "rrbhfwohfv", "krzolrglgn", "cpjesdzy", "yoifoyg", "hqqevqjugi", "ahmv", "xgaujnyclcjq", "evhyfnlohavrj", "byyvhgh", "hyw", "kedhvwy", "ysljsqminajfipds", "rglnpxfqwu", "cibpynkxg", "su", "mbntqrlwyampdg", "nig", "ldhlhqdyjcfhu", "jfymrbafmyoc", "tyjmnhlfnrtz", "dlazixtlxyvm", "fbiguhsfuqo", "rhymsno", "rkbdlchs", "ocbbwwd", "astaiamnepwkya", "mplirup", "edkxjq", "g", "exlwulswtvot", "tlnc", "vnrrzerz", "ygeraoozbtt", "yyifkin", "eo", "ua", "qgztvqdolf", "rlzddjzcshvd", "khxkdxflwxme", "kk", "zylbhoaac", "cw", "iizic", "gcdxstpz", "kjwdqeg", "earjrncmmkdel", "kbesuhquepj", "nrzbllldgdmyrpgl", "hllwnqozf", "djpchowhwevbqvjj", "zsmhylnjpktb", "pxnktxkm", "fxwiaqqb", "qjwufmwresfsfaok", "aa", "d", "iobioqm", "svjgzk", "khbzp", "euexyudhrioi", "yqsj", "ngrwqpoh", "rwuvd", "eruffmlg", "bxzovyew", "faz", "pmvfvyguqdi", "jlxnoixsy", "hyfrdngjf", "ly", "eibcapetpmeaid", "tpnwwiif", "pfgsp", "kvhhwkzvtvlhhb", "pjxurgqbtldims", "rncplkeweoirje", "akyprzzphew", "wyvfpjyglzrmhfqp", "ubheeqt", "rmbxlcmn", "taqakgim", "apsbu", "khwnykughmwrlk", "vtdlzwpbhcsbvjno", "tffmjggrmyil", "schgwrrzt", "mvndmua", "nlwpw", "glvbtkegzjs", "piwllpgnlpcnezqs", "xkelind", "urtxsezrwz", "zechoc", "vfaimxrqnyiq", "ybugjsblhzfravzn", "btgcpqwovwp", "zgxgodlhmix", "sfzdknoxzassc", "wgzvqkxuqrsqxs", "dwneyqisozq", "fg", "vhfsf", "uspujvqhydw", "eadosqafyxbmzgr", "tyff", "blolplosqnfcwx", "uwkl", "puenodlvotb", "iizudxqjvfnky", "cjcywjkfvukvveq", "jrxd", "igwb", "dftdyelydzyummmt", "uvfmaicednym", "oai", "higfkfavgeemcgo", "naefganqo", "iqebfibigljbc", "ulicojzjfrc", "igxprunj", "cymbrl", "fqmwciqtynca", "zjyagi", "mzuejrttefhdwqc", "zyiurxvf", "wrjxffzbjexsh", "wrxw", "mhrbdxjwi", "htknfa", "wfrvxqdkhbwwef", "vqsghhhutdget", "cwupzrts", "hbjnb", "wpccoa", "nx", "howbzhaoscgyk", "bilt", "wqqatye", "zceuuwg", "jxzon", "kkfj", "bwsezd", "ifdegsyjtswselk", "xweimxlnzoh", "tqthlftjblnpht", "ww", "ss", "b", "jmruuqscwjp", "nxbk", "wd", "cqkrtbxgzg", "xhppcjnq", "cfq", "tkkolzcfi", "wblxki", "ijeglxsvc", "kcqjjwcwuhvzydm", "gubqavlqffhrzz", "hiwxrgftittd", "caybc", "ncsyjlzlxyyklc", "poxcgnexmaajzuha", "dhaccuualacyl", "mtkewbprs", "oncggqvr", "sqqoffmwkplsgbrp", "ioajuppvqluhbdet", "dzwwzaelmo", "afumtqugec", "wglucmugwqi", "zveswrjevfz", "nxlbkak", "pzcejvxzeoybb", "fd", "vewj", "ivws", "zjhudtpqsfc", "zcmukotirrxx", "zksmx", "umofzhhowyftz", "zbotrokaxaryxlk", "ueolqk", "dxmzhoq", "zvu", "cjl", "esfmqgvxwfy", "npbep", "vbgjtbv", "poeugoqynkbfiv", "fewjjscjrei", "yqssxzsydgllfzmo", "urxkwcypctjkabi", "wqtldwhjouas", "tovdtkr", "onzgeyddkqwuhnim", "ffxviyvsktqrfa", "qujhd", "pvcz", "hiyjlkxmeplnrvxg", "hdykehkefp", "vepcxhozpjxtreyn", "liguhuxudbnh", "f", "ordxzm", "klgohcmmbukz", "yrmooliaobbnlap", "dutnbetocxylcey", "ywdsjegd", "cr", "blbxhjsgcuoxmqft", "ngzdc", "srfyjjumcbxole", "dazwzwtdjoyuqeqj", "xazjarqgfm", "fxyfqbeoktcc", "qrsjchxp", "iltaqzawhgu", "sgenjcfxr", "yfikp", "dvwhbyumthkiktb", "walsx", "jyajrkcvysicisab", "brdeumb", "tviihjwxdcz", "dnrrgmem", "ydgxlrjzucxyid", "cdvdpvjlagwmg", "ngnpxjkxims", "gvyhnchlimsxc", "w", "jtizpezjl", "qe", "rjzv", "vhnqvi", "qm", "iedzqswrsnfmnn", "lt", "utqfcqyrrwm", "wtelvsqrru", "fjwrhjcrtbcytn", "qmqxceuohpiffaq", "rmoybqjjgdyo", "pmxttqftypfexlv", "tg", "qa", "iqbqjlnpbf", "kgaynkddbzllecd", "tccvslp", "curkxfoimnw", "fvnyqkzlheruxr", "iiygnzfov", "coqs", "oa", "eiu", "vzemmxtklis", "lxu", "nrwsjaxzwmh", "tdayz", "oxbbemejgosgcynf", "ykbcn", "hesvnctfvdsp", "ku", "rjhykpadahbhj", "at", "sxlngbtxmqr", "wqrom", "qzyabzrco", "rbbyklndcqdj", "cnsmgmwmpbgjq", "krvnaf", "qrwfajnfahyqocdb", "fnlaozmff", "vmoymbmytjvfcgt", "cijyy", "jdgwjbztl", "swmalgbgpaplqgz", "hfl", "typttkrpfvx", "tkzpzrscwbx", "bwfqqvjcukjbsg", "nxqmxr", "x", "eyavnz", "il", "dhthp", "eyelg", "npsoqsw", "reogbmveofvusdsx", "jvdrjkhxkq", "qzjbrpljwuzpl", "czqeevvbvcwh", "vzuszqvhlmapty", "yu", "yldwwgezlqur", "vorxwgdtgjilgydq", "pknt", "bgihl", "ckorgrm", "ixylxjmlfv", "bpoaboylced", "zea", "igfagitkrext", "ipvqq", "dmoerc", "oqxbypihdv", "dtjrrkxro", "rexuhucxpi", "bvmuyarjwqpcoywa", "qwdmfpwvamisns", "bhopoqdsref", "tmnm", "cre", "ktrniqwoofoeenbz", "vlrfcsftapyujmw", "updqikocrdyex", "bcxw", "eaum", "oklsqebuzeziisw", "fzgyhvnwjcns", "dybjywyaodsyw", "lmu", "eocfru", "ztlbggsuzctoc", "ilfzpszgrgj", "imqypqo", "fump", "sjvmsbrcfwretbie", "oxpmplpcg", "wmqigymr", "qevdyd", "gmuyytguexnyc", "hwialkbjgzc", "lmg", "gijjy", "lplrsxznfkoklxlv", "xrbasbznvxas", "twn", "bhqultkyfq", "saeq", "xbuw", "zd", "kng", "uoay", "kfykd", "armuwp", "gtghfxf", "gpucqwbihemixqmy", "jedyedimaa", "pbdrx", "toxmxzimgfao", "zlteob", "adoshnx", "ufgmypupei", "rqyex", "ljhqsaneicvaerqx", "ng", "sid", "zagpiuiia", "re", "oadojxmvgqgdodw", "jszyeruwnupqgmy", "jxigaskpj", "zpsbhgokwtfcisj", "vep", "ebwrcpafxzhb", "gjykhz", "mfomgxjphcscuxj", "iwbdvusywqlsc", "opvrnx", "mkgiwfvqfkotpdz", "inpobubzbvstk", "vubuucilxyh", "bci", "dibmye", "rlcnvnuuqfvhw", "oorbyyiigppuft", "swpksfdxicemjbf", "goabwrqdoudf", "yjutkeqakoarru", "wuznnlyd", "vfelxvtggkkk", "mxlwbkbklbwfsvr", "advraqovan", "smkln", "jxxvzdjlpyurxpj", "ssebtpznwoytjefo", "dynaiukctgrzjx", "irzosjuncvh", "hcnhhrajahitn", "vwtifcoqepqyzwya", "kddxywvgqxo", "syxngevs", "batvzmziq", "mjewiyo", "pzsupxoflq", "byzhtvvpj", "cqnlvlzr", "akvmxzbaei", "mwo", "vg", "ekfkuajjogbxhjii", "isdbplotyak", "jvkmxhtmyznha", "lqjnqzrwrmgt", "mbbhfli", "bpeohsufree", "ajrcsfogh", "lucidbnlysamvy", "tutjdfnvhahxy", "urbrmmadea", "hghv", "acnjx", "athltizloasimp", "gu", "rjfozvgmdakdhao", "iephs", "uztnpqhdl", "rfuyp", "crcszmgplszwfn", "zihegt", "xbspa", "cjbmsamjyqqrasz", "ghzlgnfoas", "ljxl", "cnumquohlcgt", "jm", "mfccj", "hfedli", "vtpieworwhyiucs", "tdtuquartspkotm", "pnkeluekvelj", "ugrloq", "zljmwt", "fkyvqguqq", "tpjidglpxqfxv", "l", "tvvimvroz", "yy", "opwyfovdz", "pwlumocnyuoume", "vjqpzkcfc", "ihicd", "dtttiixlhpikbv", "goblttgvmndkqgg", "gwsibcqahmyyeagk", "prtvoju", "lcblwidhjpu", "kbu", "pey", "gkzrpc", "bqajopjjlfthe", "bc", "lqs", "zkndgojnjnxqsoqi", "zyesldujjlp", "drswybwlfyzph", "xzluwbtmoxokk", "bedrqfui", "opajzeahv", "lehdfnr", "mnlpimduzgmwszc", "velbhj", "miwdn", "wruqc", "kscfodjxg", "wcbm"};
    vector<string> exp = {"gfve", "qfpd", "lqdqrrcrwdnxeuo", "hbsfyfv", "ife", "feclhbvfuk", "ngbqqmbxqcqp", "khhqr", "dwfcayssyoqc", "omwufbdfxu", "ilebxwbcto", "ta", "hbuxhwadlpto", "tpvo", "phckcyufdqml", "lfz", "tgygdt", "nhcvpf", "shwywshtdgmb", "bkkxcvg", "monmwvytby", "qtg", "cwkuzyamnerp", "ye", "tfsrptug", "gama", "nberblt", "mf", "gttxwpuk", "xbrtspfttota", "qxru", "phknqtsdtwxcktmw", "pbqurqfxgqlojmws", "hdkbdxqg", "ge", "ukmcowoe", "xdnnl", "yjyssbsoc", "uvouaghhcyvmlk", "pbcnmhf", "qmmidmvkn", "xmywegmtuno", "vuzygv", "uxtrdsdfzfssmel", "eqrswgkaaaohxx", "ocedkt", "qghoy", "wsx", "glafbwzdd", "ryp", "nvybsfrxtlfmp", "upmsoxftumyxifyu", "xucubv", "fctkqlroq", "ppvs", "nwedtubynsb", "repgcx", "gsfomhvpmy", "kdohe", "llkmagl", "thkglauzgkeuly", "paeurdvexqlw", "akdt", "rqdll", "mumbh", "br", "fso", "qnebmfl", "lq", "xbhkkfg", "ax", "gqgsomonv", "reqqzzpw", "rlbskqgfvn", "lfvobeyolyy", "mwrvel", "ogwilaswn", "yw", "egdgye", "yaqgault", "dtlg", "iddymnl", "evxtehxtbthq", "brxpfymuvfvs", "rv", "udvmara", "fecd", "dfuydrtbfypbn", "cypqodxr", "vkmxys", "wvpfyfpkvgthq", "av", "vwduwmjpblqo", "xwnbcuggl", "flhyfac", "mqrbq", "pstsxhplrrmbeddv", "hnegtuxx", "bhhlovgcx", "had", "aysulvk", "potn", "os", "np", "lhv", "uzvgyeette", "tp", "wtsbhgkd", "eouxbldsxzm", "xhnlcrldtfthul", "xhflc", "rlaks", "phouoyhvls", "dqhqats", "koat", "pybf", "po", "wygsnxk", "kqlima", "fgxnuohrnhg", "wnnbq", "mdtrgv", "nkq", "agylw", "vomtuy", "vtdxwrclpspcn", "rdrls", "yxfeoh", "myctacn", "fdnor", "qfzwuwe", "svo", "dc", "odknlbvxrs", "hwc", "erpbaxq", "rrklkb", "wlrwyuy", "yyhga", "xwdbycdu", "htedgvsrhchox", "wr", "suhesetv", "qcagsyqggcf", "wljmg", "npdbamofynykqv", "lmq", "oyjmeqvhcrvgm", "nxtsnason", "gbndakaq", "hrtbfnq", "fguvomeepxoffg", "mat", "onlvy", "cwcchvsasdylb", "dphbfaal", "mabkapuoud", "vl", "ffjfb", "svthrfmkoxbho", "cvet", "ucgqyvopafyttrh", "vruh", "ukffmudygjavem", "dccamymhp", "kmm", "sc", "soqlh", "gcdqbcdwbwa", "gadgt", "pgowefka", "cpdxf", "sox", "fq", "lfnrhgsxkhx", "loc", "fkglorkkvx", "ggk", "nraoenhd", "rrbhfwohfv", "yoifoyg", "ahmv", "byyvhgh", "hyw", "kedhvwy", "rglnpxfqwu", "su", "mbntqrlwyampdg", "jfymrbafmyoc", "rhymsno", "rkbdlchs", "ocbbwwd", "exlwulswtvot", "tlnc", "eo", "ua", "khxkdxflwxme", "kk", "cw", "pxnktxkm", "aa", "ngrwqpoh", "rwuvd", "eruffmlg", "bxzovyew", "hyfrdngjf", "ly", "pfgsp", "akyprzzphew", "ubheeqt", "rmbxlcmn", "apsbu", "khwnykughmwrlk", "mvndmua", "nlwpw", "btgcpqwovwp", "sfzdknoxzassc", "fg", "vhfsf", "tyff", "blolplosqnfcwx", "uwkl", "puenodlvotb", "naefganqo", "cymbrl", "wrxw", "htknfa", "wfrvxqdkhbwwef", "vqsghhhutdget", "wpccoa", "nx", "bilt", "wqqatye", "bwsezd", "ww", "ss", "jmruuqscwjp", "nxbk", "wd", "cfq", "gubqavlqffhrzz", "caybc", "dhaccuualacyl", "mtkewbprs", "oncggqvr", "sqqoffmwkplsgbrp", "afumtqugec", "nxlbkak", "fd", "ueolqk", "esfmqgvxwfy", "npbep", "yqssxzsydgllfzmo", "tovdtkr", "hdykehkefp", "ordxzm", "dutnbetocxylcey", "cr", "ngzdc", "fxyfqbeoktcc", "walsx", "brdeumb", "dnrrgmem", "gvyhnchlimsxc", "qe", "qm", "lt", "utqfcqyrrwm", "wtelvsqrru", "qmqxceuohpiffaq", "pmxttqftypfexlv", "tg", "qa", "tccvslp", "coqs", "oa", "lxu", "ykbcn", "hesvnctfvdsp", "ku", "at", "sxlngbtxmqr", "wqrom", "krvnaf", "hfl", "typttkrpfvx", "nxqmxr", "dhthp", "eyelg", "npsoqsw", "reogbmveofvusdsx", "yu", "pknt", "ckorgrm", "bpoaboylced", "dmoerc", "bhopoqdsref", "tmnm", "cre", "vlrfcsftapyujmw", "bcxw", "eaum", "dybjywyaodsyw", "lmu", "eocfru", "fump", "oxpmplpcg", "qevdyd", "gmuyytguexnyc", "lmg", "lplrsxznfkoklxlv", "twn", "bhqultkyfq", "saeq", "xbuw", "kng", "uoay", "kfykd", "armuwp", "gtghfxf", "pbdrx", "adoshnx", "rqyex", "ng", "sid", "re", "vep", "ebwrcpafxzhb", "opvrnx", "vubuucilxyh", "rlcnvnuuqfvhw", "goabwrqdoudf", "wuznnlyd", "vfelxvtggkkk", "mxlwbkbklbwfsvr", "advraqovan", "smkln", "kddxywvgqxo", "syxngevs", "mwo", "vg", "bpeohsufree", "lucidbnlysamvy", "urbrmmadea", "hghv", "gu", "uztnpqhdl", "rfuyp", "xbspa", "cnumquohlcgt", "tdtuquartspkotm", "ugrloq", "fkyvqguqq", "yy", "pwlumocnyuoume", "goblttgvmndkqgg", "lcblwidhjpu", "kbu", "pey", "bc", "lqs", "xzluwbtmoxokk", "lehdfnr", "wruqc", "wcbm"};
    Solution s;

    vector<string> act = s.findAllConcatenatedWordsInADict(v);

    int i = 0, j = 0;
    while (i < exp.size() && j < act.size())
    {
        if (exp[i] != act[j])
        {
            cout << exp[i] << "\n";
            i++;
        }
        else
        {
            i++;
            j++;
        }
    }
    return 0;
}