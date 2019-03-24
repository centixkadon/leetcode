
#include "leetcode.hpp"

class Solution {
  class Hash {
  public:
    Hash() : _Val(_FNV_offset_basis), _Hash(0), _Bits() {}
    inline void resetHash() { _Val = _FNV_offset_basis; }
    inline void set(char c) {
      _changeVal(c);
      _Hash += _Val;
      _Bits.set(_Val % _Bits_prime);
    }
    inline bool test(char c) {
      _changeVal(c);
      return _Bits.test(_Val % _Bits_prime);
    }
    inline bool operator==(Hash const & _Rhs) const { return _Hash == _Rhs._Hash; }

  private:
    inline void _changeVal(char c) {
      _Val ^= _Bits_prime * c;
      _Val *= _FNV_prime;
    }
    size_t _Val, _Hash;
    static size_t const _Bits_prime = 16777ULL;
    bitset<_Bits_prime> _Bits;
    static size_t const _FNV_offset_basis = 14695981039346656037ULL;
    static size_t const _FNV_prime = 1099511628211ULL;
  };

public:
  vector<int> findSubstring(string s, vector<string> & words) {
    sort(words.begin(), words.end());
    size_t len = words.size();
    if (len != 0)
      len *= words[0].size();
    else
      return move(vector<int>());

    Hash wordHash;
    for (auto const & word : words) {
      for (auto c : word) wordHash.set(c);
      wordHash.resetHash();
    }

    vector<int> ans;
    if (s.size() >= len) {
      for (size_t i = 0; i <= s.size() - len; ++i) {
        wordHash.resetHash();
        Hash cmpHash;
        bool t = true;
        for (size_t j = 0; j < words.size(); ++j) {
          for (size_t k = 0; k < words[0].size(); ++k) {
            auto c = s[i + j * words[0].size() + k];
            if (!wordHash.test(c)) {
              t = false;
              break;
            }
            cmpHash.set(c);
          }
          if (!t) break;
          wordHash.resetHash();
          cmpHash.resetHash();
        }

        if (t && cmpHash == wordHash) {
          // vector<string> cmp(words.size());
          // for (size_t j = 0; j < words.size(); ++j) {
          //   cmp[j] = s.substr(i + j * words[0].size(), words[0].size());
          // }
          // sort(cmp.begin(), cmp.end());
          // if (cmp == words) {
          ans.push_back(i);
          // }
        }
      }
    }
    return move(ans);
  }
};

int main() {
  {
    auto check = solve(&Solution::findSubstring);
    check({}, "", {});
    check({}, "abcd", {});
    check({ 0, 1, 2, 3, 4 }, "abcd", { "", "" });
    check({}, "afbdce", { "ad", "be", "cf" });
    check({ 0, 9 }, "barfoothefoobarman", { "foo", "bar" });
    check({}, "wordgoodgoodgoodbestword", { "word", "good", "best", "word" });
    check({}, "bbabbbab", { "ab", "bb", "bc", "ac" });
    check({ 187 }, "dlmogiklbqfggokuonfgugiyammwvwhbjvrqgdbjtipcwzwmobtjjdhmpvknrsqbpjtvmwfifukbwgokjjvvmeheatttljwdupygofotcywygmksvipkmyqmrjifueiouiukoldqlzquocojkdvzdlnuuvbqajewubgiolazmsvaujmfohervtorppipbolvrtdfefhqxcrrofycmewjykbnzjeazrxrkayohfgekzwyewctbyczidokoskojihvkflslryxruvxrzquytvgyjsndddmnkhzrstclsbeowchwsbwnwemhxbkcgwpqfqjzmmlenpumrckmdgzcmnjjqulwscoytyxhkklzahntjzfphhruwadnwpjptypmwovizijzqzuzycogjhahkdugugxoemccbymagvbyuxytzobkwbsigoobuoraatedrqfamiyigydhpeslhmvoajrxzixabcfvslxgvvpbwujlzdygptureloetogxslsmyrtuokxkeivflvmcoiutwkzryfoqsidtzypqkmaqxywktknisjdoteisjykdhpyipnyzcbqzzolsyycsjfjdjrxupjayzyhqohqqiirjyccwdgoomxtxqqugcwedwntkxlcfvvrtatpfbgtnfnnwfjchfikdwgotrsanorgqmyvoeqdldshldlsiufoslencwprmhyevwzlcqrpvlzgpkbzggnytrnxqdpekpjhnivraogwzfeoqfoynbzgvmelpvpbkyjxjgojuwhtcmkurysfbrnwerjvozxazixionukkbfonpihpcorwbpcvzxjaukzejksxeejhkxxzhgpjuihvxjqyhaydmaivkcuqhdztcyulelvyteutokrxmscasmwepswyyxrawnmazjbsnvndhfcwzfwrruxinvilsbnopbroksiapwfydkwcptvipstepbphffyugrktlsvaqaatkxxbssmhmhmbidjpijjravklofnghnaumxvesjoeqcibhtqsccjextpnaeuhtwdgvbknkaubccemvuezyndwiujkyftrbxxzykmkkilpkrdhohgmwjigduqdbjvdgueggqrtbeknwnvkubysnjysdowgztjipnowghpjmbwkorwkvuckfaciqaprvazlqqjyxahlbdxpxvzusdexfiivlzogbotrgerfeathgqydmxzgcddhnleykthmjcfphzwnzpvfgtkutjavoffcrjcdejrpoxevydkxsffabruwbwtrcytvkyyqhqgvpmsnpdmiktinlflmdffffzcrxbigtqeicyxudlcofmdqtpexwjebkhtjidsdtwlvwkpavtqaitsbkyagifiumdewgwzzumwqyoqtjgwrcqvmpvtzadtogxmmvnlrzjixxathjpylhvzwruvtxpkdowrmkedlonjloeuxtvkcqjzjeuddlnhalamvfrhvfsitwdsryetqnu", { "pbolvrtdfefhqxcrrofyc", "mewjykbnzjeazrxrkayoh", "fgekzwyewctbyczidokos", "kojihvkflslryxruvxrzq", "uytvgyjsndddmnkhzrstc", "lsbeowchwsbwnwemhxbkc", "gwpqfqjzmmlenpumrckmd", "gzcmnjjqulwscoytyxhkk", "lzahntjzfphhruwadnwpj", "ptypmwovizijzqzuzycog", "jhahkdugugxoemccbymag", "vbyuxytzobkwbsigoobuo", "raatedrqfamiyigydhpes", "lhmvoajrxzixabcfvslxg", "vvpbwujlzdygptureloet", "ogxslsmyrtuokxkeivflv", "mcoiutwkzryfoqsidtzyp", "qkmaqxywktknisjdoteis", "jykdhpyipnyzcbqzzolsy", "ycsjfjdjrxupjayzyhqoh", "qqiirjyccwdgoomxtxqqu", "gcwedwntkxlcfvvrtatpf", "bgtnfnnwfjchfikdwgotr", "sanorgqmyvoeqdldshldl", "siufoslencwprmhyevwzl", "cqrpvlzgpkbzggnytrnxq" });
  }
  return 0;
}

Settings;
