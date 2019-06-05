#ifndef TESTS_TEST_DEFINE_H_
#define TESTS_TEST_DEFINE_H_

#include <unity/unity.h>
#include "accelerator/config.h"

#ifdef __cplusplus
extern "C" {
#endif

#define STR_HELPER(num) #num
#define STR(num) STR_HELPER(num)

#define TRYTES_81_1                                                            \
  "LCIKYSBE9IHXLIKCEJTTIQOTTAWSQCCQQ9A9VOKIWRBWVPXMCGUENWVVMQAMPEIVHEQ9JXLCNZ" \
  "OORVZTZ"
#define TRYTES_81_2                                                            \
  "RVORZ9SIIP9RCYMREUIXXVPQIPHVCNPQ9HZWYKFWYWZRE9JQKG9REPKIASHUUECPSQO9JT9XNM" \
  "VKWYGVA"
#define TRYTES_81_3                                                            \
  "BGBQJCVSOESTAVKHKD9QBNYVHUUEQUGZ9BEUAPG9HGQWAHMDAJXKDPUZPRBZVVIPRHMERPOBCD" \
  "YB99999"
#define BUNDLE_HASH                                                            \
  "LVXEVZABVCIFEDSCONKEVEYBSIRMXGHLJDKSKQHTKZC9ULEAPSLKOOWCCZJGWSIISDDSEVUQHV" \
  "GPFOSIW"
#define TAG_MSG "TANGLEACCELERATOR9999999999"
#define FIND_TAG_MSG "TAFINDTXN999999999999999999"
#define TAG_MSG_LEN 27
#define VALUE 100
#define TIMESTAMP 1546436542
#define CURRENT_INDEX 1
#define LAST_INDEX 2
#define NONCE "THISTANGLEACCELERATORNONCES"

#define TRYTES_2673_LEN 2673
#define TRYTES_2673_1                                                        \
  "XCRBOBVBVBYB999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999BXEOYAONFPBGKEUQZDUZZZODHWJDWHEOYY9AENYF9VNLX" \
  "ZHXBOODCOTYXW9MGGINTEJPLK9AGOPTPODVX9999999999999999999999999999ZTHONTES" \
  "T99999999999999999B9AWBZD99999999999999999999ORMJWRXVFYYFDFCKJBZAXHYFZHJ" \
  "LWYULGXLXUIAJSDLWXEUSPWRUTKPCNG9AZLCTJQFAC9XJKXDLWCFYD999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "PYTHONTEST99999999999999999999999999999999999999999999NC99999999XRVYE999" \
  "999999999"

#define TRYTES_2673_2                                                        \
  "BYSWEAUTWXHXZ9YBZISEK9LUHWGMHXCGEVNZHRLUWQFCUSDXZHOFHWHL9MQPVJXXZLIXPX"   \
  "PXF9KYEREFSKCPKYIIKPZVLHUTDFQKKVVBBN9ATTLPCNPJDWDEVIYYLGPZGCWXOBDXMLJC9V" \
  "O9QXTTBLAXTTBFUAROYEGQIVB9MJWJKXJMCUPTWAUGFZBTZCSJVRBGMYXTVBDDS9MYUJCPZ9" \
  "YDWWQNIPUAIJXXSNLKUBSCOIJPCLEFPOXFJREXQCUVUMKSDOVQGGHRNILCO9GNCLWFM9APMN" \
  "MWYASHXQAYBEXF9QRIHIBHYEJOYHRQJAOKAQ9AJJFQ9WEIWIJOTZATIBOXQLBMIJU9PCGBLV" \
  "DDVFP9CFFSXTDUXMEGOOFXWRTLFGV9XXMYWEMGQEEEDBTIJ9OJOXFAPFQXCDAXOUDMLVYRMR" \
  "LUDBETOLRJQAEDDLNVIRQJUBZBO9CCFDHIX9MSQCWYAXJVWHCUPTRSXJDESISQPRKZAFKFRU" \
  "LCGVRSBLVFOPEYLEE99JD9SEBALQINPDAZHFAB9RNBH9AZWIJOTLBZVIEJIAYGMC9AZGNFWG" \
  "RSWAXTYSXVROVNKCOQQIWGPNQZKHUNODGYADPYLZZZUQRTJRTODOUKAOITNOMWNGHJBBA99Q" \
  "UMBHRENGBHTH9KHUAOXBVIVDVYYZMSEYSJWIOGGXZVRGN999EEGQMCOYVJQRIRROMPCQBLDY" \
  "IGQO9AMORPYFSSUGACOJXGAQSPDY9YWRRPESNXXBDQ9OZOXVIOMLGTSWAMKMTDRSPGJKGBXQ" \
  "IVNRJRFRYEZ9VJDLHIKPSKMYC9YEGHFDS9SGVDHRIXBEMLFIINOHVPXIFAZCJKBHVMQZEVWC" \
  "OSNWQRDYWVAIBLSCBGESJUIBWZECPUCAYAWMTQKRMCHONIPKJYYTEGZCJYCT9ABRWTJLRQXK" \
  "MWY9GWZMHYZNWPXULNZAPVQLPMYQZCYNEPOCGOHBJUZLZDPIXVHLDMQYJUUBEDXXPXFLNRGI" \
  "PWBRNQQZJSGSJTTYHIGGFAWJVXWL9THTPWOOHTNQWCNYOYZXALHAZXVMIZE9WMQUDCHDJMIB" \
  "WKTYH9AC9AFOT9DPCADCV9ZWUTE9QNOMSZPTZDJLJZCJGHXUNBJFUBJWQUEZDMHXGBPTNSPZ" \
  "BR9TGSKVOHMOQSWPGFLSWNESFKSAZY9HHERAXALZCABFYPOVLAHMIHVDBGKUMDXC9WHHTIRY" \
  "HZVWNXSVQUWCR9M9RAGMFEZZKZ9XEOQGOSLFQCHHOKLDSA9QCMDGCGMRYJZLBVIFOLBIJPRO" \
  "KMHOYTBTJIWUZWJMCTKCJKKTR9LCVYPVJI9AHGI9JOWMIWZAGMLDFJA9WU9QAMEFGABIBEZN" \
  "NAL9OXSBFLOEHKDGHWFQSHMPLYFCNXAAZYJLMQDEYRGL9QKCEUEJ9LLVUOINVSZZQHCIKPAG" \
  "MT9CAYIIMTTBCPKWTYHOJIIY9GYNPAJNUJ9BKYYXSV9JSPEXYMCFAIKTGNRSQGUNIYZCRT9F" \
  "OWENSZQPD9ALUPYYAVICHVYELYFPUYDTWUSWNIYFXPX9MICCCOOZIWRNJIDALWGWRATGLJXN" \
  "AYTNIZWQ9YTVDBOFZRKO9CFWRPAQQRXTPACOWCPRLYRYSJARRKSQPR9TCFXDVIXLP9XVL99E" \
  "RRDSOHBFJDJQQGGGCZNDQ9NYCTQJWVZIAELCRBJJFDMCNZU9FIZRPGNURTXOCDSQGXTQHKHU" \
  "ECGWFUUYS9J9NYQ9U9P9UUP9YMZHWWWCIASCFLCMSKTELZWUGCDE9YOKVOVKTAYPHDF9ZCCQ" \
  "AYPJIJNGSHUIHHCOSSOOBUDOKE9CJZGYSSGNCQJVBEFTZFJ9SQUHOASKRRGBSHWKBCBWBTJH" \
  "OGQ9WOMQFHWJVEG9NYX9KWBTCAIXNXHEBDIOFO9ALYMFGRICLCKKLG9FOBOX9PDWNQRGHBKH" \
  "GKKRLWTBEQMCWQRLHAVYYZDIIPKVQTHYTWQMTOACXZOQCDTJTBAAUWXSGJF9PNQIJ9AJRUMU" \
  "VCPWYVYVARKR9RKGOUHHNKNVGGPDDLGKPQNOYHNKAVVKCXWXOQPZNSLATUJT9AUWRMPPSWHS" \
  "TTYDFAQDXOCYTZHOYYGAIM9CELMZ9AZPWB9MJXGHOKDNNSZVUDAGXTJJSSZCPZVPZBYNNTUQ" \
  "ABSXQWZCHDQSLGK9UOHCFKBIBNETK9999999999999999999999999999999999999999999" \
  "99999999999999999999999999999999999999NOXDXXKUDWLOFJLIPQIBRBMGDYCPGDNLQO" \
  "LQS99EQYKBIU9VHCJVIPFUYCQDNY9APGEVYLCENJIOBLWNB999999999XKBRHUD99C999999" \
  "99NKZKEKWLDKMJCI9N9XQOLWEPAYWSH9999999999999999999999999KDDTGZLIPBNZKMLT" \
  "OLOXQVNGLASESDQVPTXALEKRMIOHQLUHD9ELQDBQETS9QFGTYOYWLNTSKKMVJAUXSIROUICD" \
  "OXKSYZTDPEDKOQENTJOWJONDEWROCEJIEWFWLUAACVSJFTMCHHXJBJRKAAPUDXXVXFWP9X99" \
  "99IROUICDOXKSYZTDPEDKOQENTJOWJONDEWROCEJIEWFWLUAACVSJFTMCHHXJBJRKAAPUDXX" \
  "VXFWP9X9999"

#define TRYTES_2187_1                                                        \
  "XCRBOBVBVBYB999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999999999999999999999999"

#define TEST_BUNDLE_HASH                                                       \
  "QBFXQETKSHDYPFUDO9ILVCAVQIXOHXKCECZYFLPBNVIX9JUXQZJE9URQEEUWPWYZOIACTCGZX9" \
  "IDIODCA "
#define TEST_CHID                                                              \
  "WYEVIWJN9DF9SBQHBUWYUECD9KD9BQHQXHOGQDTVKKYBRQUFQYGOFOTHREGVSKSSEVXMFOEHWN" \
  "KHLHDKQ"

#define TEST_PAYLOAD                                                           \
  "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer aliquam "  \
  "velit ac placerat dignissim. Suspendisse interdum nisl velit, quis "        \
  "consequat lacus gravida vitae. Mauris in faucibus eros. Phasellus "         \
  "eleifend bibendum magna in iaculis. Nullam quis nibh posuere, efficitur "   \
  "metus nec, cursus justo. Cras in eros velit. Suspendisse tempus a ipsum "   \
  "et vehicula. Nulla sed ipsum porttitor, molestie enim ut, porttitor "       \
  "neque. Aenean rutrum nunc eros, vitae ullamcorper neque pretium ut. Etiam " \
  "tempor libero sit amet fringilla eleifend. Maecenas varius nunc vel porta " \
  "bibendum. Vestibulum ultricies sagittis elit eu rutrum. Duis id orci at "   \
  "eros vehicula suscipit a ac tortor. Morbi nulla nisi, laoreet vel leo "     \
  "vel, dignissim convallis sem. Nunc id lacus consectetur, iaculis metus "    \
  "ac, dictum erat. Curabitur eget erat eu eros hendrerit dapibus quis nec "   \
  "diam. Sed vulputate velit a mi ullamcorper, ut vestibulum felis "           \
  "tincidunt. Fusce et euismod elit. Phasellus augue turpis, efficitur a "     \
  "augue ac, rutrum vehicula nisl. Morbi ullamcorper, dui non ultrices "       \
  "consequat, odio felis aliquam dui, et mattis nibh purus vitae felis. "      \
  "Pellentesque rhoncus diam enim, in porttitor turpis dignissim in. "         \
  "Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere "  \
  "cubilia Curae;"

#ifdef __cplusplus
}
#endif

#endif  // TESTS_TEST_DEFINE_H_
