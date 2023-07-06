/* Verify the support of nested containers in alaio multi-index table
 * For each action, an example regarding how to use the action with the alacli command line is given.
 *
 * std:pair<T1,T2> is a struct with 2 fields first and second,
 * std::map<K,V> is handled as an array/vector of pairs/structs by ALAIO with implicit fields key, value,
 * the cases of combined use of key/value and first/second involving map,pair in the alacli are documented here.
 * so handling of std::pair is NOT the same as the handling of a general struct such as struct mystruct!
 *
 * When assigning data input with alacli:
 *      [] represents an empty vector<T>/set<T> or empty map<T1,T2> where T, T1, T2 can be any composite types
 *      null represents an uninitialized std::optional<T> where T can be any composite type
 *      BUT [] or null can NOT be used to represent an empty struct or empty std::pair
 */

#include <alaio/alaio.hpp>

#include <vector>
#include <set>
#include <optional>
#include <map>
#include <tuple>

using namespace alaio;
using namespace std;

#define  SETCONTAINERVAL(x) do { \
   require_auth(user); \
   psninfoindex2 tblIndex(get_self(), get_first_receiver().value); \
   auto iter = tblIndex.find(user.value); \
   if (iter == tblIndex.end()) { \
      tblIndex.emplace(user, [&](auto &row) { \
         row.key = user; \
         row.x = x; \
     }); \
   } else { \
      tblIndex.modify(iter, user, [&]( auto& row ) { \
      row.x = x; \
      }); \
   } \
 } while(0)

struct mystruct
{
    uint64_t   _count;
    string     _strID;
};


typedef set<uint16_t> set_uint16;
typedef vector<uint16_t> vec_uint16;
typedef optional<uint16_t> op_uint16;
typedef map<uint16_t, uint16_t> mp_uint16;
typedef pair<uint16_t, uint16_t> pr_uint16;

typedef vector< op_uint16 > vec_op_uint16;
typedef optional< mystruct > op_struc;
typedef tuple<uint16_t, uint16_t> tup_uint16;

class [[alaio::contract("nested_container_multi_index")]] nestcontnmi : public alaio::contract {
    private:
        struct [[alaio::table]] person2 {
            name key;

            set< set_uint16 > stst;
            set< vec_uint16 > stv;
            set< op_uint16 > sto;
            set< mp_uint16 > stm;
            set< pr_uint16 > stp;
            set< tup_uint16 > stt;

            vector< set_uint16 > vst;
            vector< vec_uint16 > vv;
            vector< op_uint16 > vo;
            vector< mp_uint16 > vm;
            vector< pr_uint16 > vp;
            vector< tup_uint16 > vt; 

            optional< set_uint16 > ost;
            optional< vec_uint16 > ov;
            optional< op_uint16 > oo;
            optional< mp_uint16 > om;
            optional< pr_uint16 > op;
            optional< tup_uint16 > ot;

            map< uint16_t, set_uint16 > mst;
            map< uint16_t, vec_uint16 > mv;
            map< uint16_t, op_uint16 > mo;
            map< uint16_t, mp_uint16 > mm;
            map< uint16_t, pr_uint16 > mp;
            map< uint16_t, tup_uint16 > mt;

            pair< uint16_t, set_uint16 > pst;
            pair< uint16_t, vec_uint16 > pv;
            pair< uint16_t, op_uint16 > po;
            pair< uint16_t, mp_uint16 > pm;
            pair< uint16_t, pr_uint16 > pp;
            pair< uint16_t, tup_uint16 > pt;

            tuple< uint16_t, vec_uint16, vec_uint16 > tv;     
            tuple< uint16_t, set_uint16, set_uint16 > tst;
            tuple< op_uint16, op_uint16, op_uint16,op_uint16,op_uint16 > to;
            tuple< uint16_t, mp_uint16, mp_uint16 > tm;
            tuple< uint16_t, pr_uint16, pr_uint16 > tp;      
            tuple< tup_uint16, tup_uint16,  tup_uint16 > tt;

            vector< op_struc > vos;
            pair< uint16_t, vec_op_uint16 > pvo;

            uint64_t primary_key() const { return key.value; }
        };
        using psninfoindex2 = alaio::multi_index<"people2"_n, person2>;


    public:
        using contract::contract;

        nestcontnmi(name receiver, name code,  datastream<const char*> ds): contract(receiver, code, ds) {}

        [[alaio::action]]
        void setstst(name user, const set< set_uint16 >& stst){
            SETCONTAINERVAL(stst);
            alaio::print("type defined set< set< uint16_t >> stored successfully!");
        }

        [[alaio::action]]
        void setstv(name user, const set< vec_uint16 >& stv){
            SETCONTAINERVAL(stv);
            alaio::print("type defined set< vector< uint16_t >> stored successfully!");
        }

        [[alaio::action]]
        void setsto(name user, const set< op_uint16 >& sto){
            SETCONTAINERVAL(sto);
            alaio::print("type defined set< optional< uint16_t >> stored successfully!");
        }

        [[alaio::action]]
        void setstm(name user, const set< mp_uint16 >& stm){
            SETCONTAINERVAL(stm);
            alaio::print("type defined set< map< uint16_t, uint16_t>> stored successfully!");
        }

        [[alaio::action]]
        void setstp(name user, const set< pr_uint16 >& stp){
            SETCONTAINERVAL(stp);
            alaio::print("type defined set< pair< uint16_t, uint16_t >> stored successfully");
        }

        [[alaio::action]]
        void setstt(name user, const set< tup_uint16 >& stt){
            SETCONTAINERVAL(stt);
            alaio::print("type defined set< tuple< uint16_t, uint16_t >> stored successfully!");
        }


        [[alaio::action]]
        void setvst(name user, const vector< set_uint16 >& vst){
            SETCONTAINERVAL(vst);
            alaio::print("type defined vector< set< uint16_t >> stored successfully!");
        }

        [[alaio::action]]
        void setvv(name user, const vector< vec_uint16 >& vv){
            SETCONTAINERVAL(vv);
            alaio::print("type defined vector< vector< uint16_t >> stored successfully!");
        }

        [[alaio::action]]
        void setvo(name user, const vector< op_uint16 >& vo){
            SETCONTAINERVAL(vo);
            alaio::print("type defined vector< optional< uint16_t >> stored successfully!");
        }

        [[alaio::action]]
        void setvm(name user, const vector< mp_uint16 >& vm){
            SETCONTAINERVAL(vm);
            alaio::print("type defined vector< map< uint16_t, uint16_t>> stored successfully!");
        }

        [[alaio::action]]
        void setvp(name user, const vector< pr_uint16 >& vp){
            SETCONTAINERVAL(vp);
            alaio::print("type defined vector< pair< uint16_t, uint16_t >> stored successfully");
        }

        [[alaio::action]]
        void setvt(name user, const vector< tup_uint16 >& vt){
            SETCONTAINERVAL(vt);
            alaio::print("type defined vector< tuple< uint16_t, uint16_t >> stored successfully!");
        }


        [[alaio::action]]
        void setost(name user, const optional< set_uint16 >& ost){
            SETCONTAINERVAL(ost);
            alaio::print("type defined optional< set< uint16_t >> stored successfully!");
        }

        [[alaio::action]]
        void setov(name user, const optional< vec_uint16 >& ov){
            SETCONTAINERVAL(ov);
            alaio::print("type defined optional< vector< uint16_t >> stored successfully!");
        }

        [[alaio::action]] 
        void setoo(name user, const optional< op_uint16 > & oo){
            SETCONTAINERVAL(oo);
            alaio::print("type defined optional< optional< uint16_t >> stored successfully!");
        }

        [[alaio::action]]
        void setom(name user, const optional< mp_uint16 >& om){
            SETCONTAINERVAL(om);
            alaio::print("type defined optional< map< uint16_t, uint16_t>> stored successfully!");
        }

        [[alaio::action]]
        void setop(name user, const optional< pr_uint16 >& op){
            SETCONTAINERVAL(op);
            alaio::print("type defined optional< pair< uint16_t, uint16_t >> stored successfully");
        }

        [[alaio::action]]
        void setot(name user, const optional< tup_uint16 >& ot){
            SETCONTAINERVAL(ot);
            alaio::print("type defined optional< tuple< uint16_t, uint16_t >> stored successfully!");
        }


        [[alaio::action]]
        void setmst(name user, const map< uint16_t, set_uint16 >& mst){
            SETCONTAINERVAL(mst);
            alaio::print("type defined map< set< uint16_t >> stored successfully!");
        }

        [[alaio::action]]
        void setmv(name user, const map< uint16_t, vec_uint16 >& mv){
            SETCONTAINERVAL(mv);
            alaio::print("type defined map< vector< uint16_t >> stored successfully!");
        }

        [[alaio::action]] 
        void setmo(name user, const map< uint16_t, op_uint16 > & mo){
            SETCONTAINERVAL(mo);
            alaio::print("type defined map< optional< uint16_t >> stored successfully!");
        }

        [[alaio::action]]
        void setmm(name user, const map< uint16_t, mp_uint16 >& mm){
            SETCONTAINERVAL(mm);
            alaio::print("type defined map< map< uint16_t, uint16_t>> stored successfully!");
        }

        [[alaio::action]]
        void setmp(name user, const map< uint16_t, pr_uint16 >& mp){
            SETCONTAINERVAL(mp);
            alaio::print("type defined map< pair< uint16_t, uint16_t >> stored successfully");
        }

        [[alaio::action]]
        void setmt(name user, const map< uint16_t, tup_uint16 >& mt){
            SETCONTAINERVAL(mt);
            alaio::print("type defined map< uint16_t, tuple< uint16_t, uint16_t >> stored successfully!");
        }


        [[alaio::action]]
        void setpst(name user, const pair< uint16_t, set_uint16 >& pst){
            SETCONTAINERVAL(pst);
            alaio::print("type defined pair< set< uint16_t >> stored successfully!");
        }

        [[alaio::action]]
        void setpv(name user, const pair< uint16_t, vec_uint16 >& pv){
            SETCONTAINERVAL(pv);
            alaio::print("type defined pair< vector< uint16_t >> stored successfully!");
        }

        [[alaio::action]] 
        void setpo(name user, const pair< uint16_t, op_uint16 > & po){
            SETCONTAINERVAL(po);
            alaio::print("type defined pair< optional< uint16_t >> stored successfully!");
        }

        [[alaio::action]]
        void setpm(name user, const pair< uint16_t, mp_uint16 >& pm){
            SETCONTAINERVAL(pm);
            alaio::print("type defined pair< map< uint16_t, uint16_t>> stored successfully!");
        }

        [[alaio::action]]
        void setpp(name user, const pair< uint16_t, pr_uint16 >& pp){
            SETCONTAINERVAL(pp);
            alaio::print("type defined pair< pair< uint16_t, uint16_t >> stored successfully");
        }

        [[alaio::action]]
        void setpt(name user, const pair< uint16_t, tup_uint16 >& pt){
            SETCONTAINERVAL(pt);
            alaio::print("type defined pair< uint16_t, tuple< uint16_t, uint16_t >> stored successfully!");
        }

        [[alaio::action]]
        void settst(name user, const tuple<uint16_t, set_uint16, set_uint16>& tst){
            SETCONTAINERVAL(tst);
            alaio::print("type defined tuple< uint16_t, set< uint16_t >, set< uint16_t >> stored successfully!");
        }

        [[alaio::action]]
        void settv(name user, const tuple<uint16_t, vec_uint16, vec_uint16>& tv){
            SETCONTAINERVAL(tv);
            alaio::print("type defined tuple< uint16_t, vector< uint16_t >, vector< uint16_t > stored successfully!");
        }

        [[alaio::action]] 
        void setto(name user, const tuple<op_uint16, op_uint16, op_uint16,op_uint16,op_uint16> & to){
            SETCONTAINERVAL(to);
            alaio::print("type defined tuple< optional < uint16_t >, optional < uint16_t >, ... > stored successfully!");
        }

        [[alaio::action]]
        void settm(name user, const tuple<uint16_t, mp_uint16, mp_uint16>& tm){
            SETCONTAINERVAL(tm);
            alaio::print("type defined tuple< map< uint16_t, map< uint16_t, uint16_t>, map< uint16_t, uint16_t> >> stored successfully!");
        }

        [[alaio::action]]
        void settp(name user, const tuple<uint16_t, pr_uint16, pr_uint16>& tp){
            SETCONTAINERVAL(tp);
            alaio::print("type defined tuple< uint16_t, pair< uint16_t, uint16_t >, pair< uint16_t, uint16_t >> stored successfully");
        }

        [[alaio::action]]
        void settt(name user, const tuple< tup_uint16, tup_uint16, tup_uint16 >& tt){
            SETCONTAINERVAL(tt);
            alaio::print("type defined tuple< tuple< uint16_t, uint16_t >, ... > stored successfully!");
        }


        [[alaio::action]]
        void setvos(name user, const vector<op_struc>& vos)
        {
            SETCONTAINERVAL(vos);
            alaio::print("vector<optional<mystruct>> stored successfully");
        }

        [[alaio::action]]
        void setpvo(name user, const pair<uint16_t, vec_op_uint16>& pvo)
        {
            SETCONTAINERVAL(pvo);
            alaio::print("pair<uint16_t, vector<optional<uint16_t>>> stored successfully");
        }
};