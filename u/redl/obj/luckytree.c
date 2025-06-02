// This program is a part of NITAN MudLIB 
// redl 2013/12/23
#include <ansi.h>
inherit ITEM;

#define R_LEVEL 10
#define R_ONLINEDAY 1
#define SEND_NUM 28

void post_channel(string arg);
int gf3query(string qq);

mapping *giftlists = ({//amountΪÿ100��ʱ�ɷ�������
        //level 1����Ҫ�Ľ��ղſ�
                ([
                        "id"                    :                       "xunzhang",
                        "level"                 :                       1,
                        "file"                  :                       "/clone/medal/daomu_xunzhang",
                        "amount"                :                       1
                        ]),
                ([
                        "id"                    :                       "ntb",//100�䶯��;��
                        "level"                 :                       1,
                        "file"                  :                       "/u/redl/npc/obj/ntb",
                        "amount"                :                       10
                        ]),
        //level 2�������ף���
                ([
                        "id"                    :                       "ntb",//100�䶯��;��
                        "level"                 :                       2,
                        "file"                  :                       "/u/redl/npc/obj/ntb",
                        "amount"                :                       3
                        ]),
                ([
                        "id"                    :                       "xunzhang",
                        "level"                 :                       2,
                        "file"                  :                       "/clone/medal/diamond_xunzhang",
                        "amount"                :                       6
                        ]),
                ([
                        "id"                    :                       "slsj",//ʥ��ˮ�����̼���װ��ϵͳ��ǿ������
                        "level"                 :                       2,
                        "file"                  :                       "/clone/goods/shengling_crystal",
                        "amount"                :                       8
                        ]),
                ([
                        "id"                    :                       "qhsj",//ǿ��ˮ��
                        "level"                 :                       2,
                        "file"                  :                       "/clone/goods/qianghua_crystal",
                        "amount"                :                       7
                        ]),
                ([
                        "id"                    :                       "jll",//�������¯��������Ʒ������û��Ը���������滨Ǯ
                        "level"                 :                       2,
                        "file"                  :                       "/clone/goods/jiulonglu",
                        "amount"                :                       6
                        ]),
                ([
                        "id"                    :                       "ryj",//���¾���Ը���������
                        "level"                 :                       2,
                        "file"                  :                       "/clone/goods/riyue-jing",
                        "amount"                :                       3
                        ]),
                ([
                        "id"                    :                       "byh",//������
                        "level"                 :                       2,
                        "file"                  :                       "/d/dongtian/obj/baiyuhu",
                        "amount"                :                       4
                        ]),
        //level 3��С����ף����߽��տ�
                ([
                        "id"                    :                       "xunzhang",
                        "level"                 :                       3,
                        "file"                  :                       "/clone/medal/vip_xunzhang",
                        "amount"                :                       7
                        ]),
                ([
                        "id"                    :                       "dtzb1",//������̬װ�����߱�ʯ
                        "level"                 :                       3,
                        "file"                  :                       "",
                        "amount"                :                       12
                        ]),
                ([
                        "id"                    :                       "ldb",//���۱ң������������Ʒ���Կ��Զ෢
                        "level"                 :                       3,
                        "file"                  :                       "/d/dongtian/obj/liudibi",
                        "amount"                :                       9
                        ]),
                ([
                        "id"                    :                       "wm",//����֮��
                        "level"                 :                       3,
                        "file"                  :                       "/clone/goods/noname",
                        "amount"                :                       2
                        ]),
                ([
                        "id"                    :                       "xzx",//ѫ�����ӣ��������ѫ�£����Զ෢
                        "level"                 :                       3,
                        "file"                  :                       "/clone/goods/xunzhang_xiang",
                        "amount"                :                       13
                        ]),
                ([
                        "id"                    :                       "ly2",//��Ԫ2
                        "level"                 :                       3,
                        "file"                  :                       "/clone/goods/dragon_soul2",
                        "amount"                :                       3
                        ]),
                ([
                        "id"                    :                       "fhm",//����ľ
                        "level"                 :                       3,
                        "file"                  :                       "/u/redl/obj/fanghuamu",
                        "amount"                :                       6
                        ]),
                ([
                        "id"                    :                       "hytj",//���ߣ�����쾧�����᲻�û�Ǯ�����һ����ͷ
                        "level"                 :                       3,
                        "file"                  :                       "/clone/goods/tianjing",
                        "amount"                :                       8
                        ]),
                ([
                        "id"                    :                       "rune26",
                        "level"                 :                       3,
                        "file"                  :                       "/clone/tessera/rune26",
                        "amount"                :                       60
                        ]),
                ([
                        "id"                    :                       "cms",//����ʯ
                        "level"                 :                       3,
                        "file"                  :                       "/clone/goods/cemashi",
                        "amount"                :                       7
                        ]),
                ([
                        "id"                    :                       "taozhuang",//����Ů��
                        "level"                 :                       3,
                        "file"                  :                       "/clone/goods/luck_neck",
                        "amount"                :                       17
                        ]),
                ([
                        "id"                    :                       "taozhuang",//����Ů��
                        "level"                 :                       3,
                        "file"                  :                       "/clone/goods/luck_charm",
                        "amount"                :                       17
                        ]),
                ([
                        "id"                    :                       "taozhuang",//����Ů��
                        "level"                 :                       3,
                        "file"                  :                       "/clone/goods/luck_ring",
                        "amount"                :                       17
                        ]),
        //level 4������뿪���ǾͿ���
                ([
                        "id"                    :                       "xunzhang",
                        "level"                 :                       4,
                        "file"                  :                       "/clone/medal/yongshi_xunzhang",
                        "amount"                :                       8
                        ]),
                ([
                        "id"                    :                       "rune14",
                        "level"                 :                       4,
                        "file"                  :                       "/clone/tessera/rune14",
                        "amount"                :                       189
                        ]),
                ([
                        "id"                    :                       "zyw",//������
                        "level"                 :                       4,
                        "file"                  :                       "/clone/fam/max/zhenyu",
                        "amount"                :                       59
                        ]),
                ([
                        "id"                    :                       "ljd",//���׵�
                        "level"                 :                       4,
                        "file"                  :                       "/clone/fam/max/longjia",
                        "amount"                :                       119
                        ]),
                ([
                        "id"                    :                       "yqw",//������
                        "level"                 :                       4,
                        "file"                  :                       "/clone/medicine/yuqingwan",
                        "amount"                :                       161
                        ]),
                ([
                        "id"                    :                       "wxts",//��������
                        "level"                 :                       4,
                        "file"                  :                       "/d/dongtian/obj/wanxiangbook",
                        "amount"                :                       184
                        ]),
                /*
                        "id"                    :                       "qljp",//ǧ����Ʊ
                        "level"                 :                       4,
                        "file"                  :                       "/clone/money/thousand-gold",
                        "amount"                :                       200
                        ]),*/
                ([
                        "id"                    :                       "bs1",
                        "level"                 :                       4,
                        "file"                  :                       "/clone/tessera/mdiamond",
                        "amount"                :                       40
                        ]),
                ([
                        "id"                    :                       "bs2",
                        "level"                 :                       4,
                        "file"                  :                       "/clone/tessera/memerald",
                        "amount"                :                       40
                        ]),
                ([
                        "id"                    :                       "bs3",
                        "level"                 :                       4,
                        "file"                  :                       "/clone/tessera/msapphire",
                        "amount"                :                       40
                        ]),
                ([
                        "id"                    :                       "bs4",
                        "level"                 :                       4,
                        "file"                  :                       "/clone/tessera/mruby",
                        "amount"                :                       40
                        ]),
                ([
                        "id"                    :                       "bs5",
                        "level"                 :                       4,
                        "file"                  :                       "/clone/tessera/mtopaz",
                        "amount"                :                       40
                        ]),
                ([
                        "id"                    :                       "dtzb2",//��˵��̬װ�����߱�ʯ
                        "level"                 :                       4,
                        "file"                  :                       "",
                        "amount"                :                       171
                        ]),
        });

void set_giftlists()
{
        int sizeu = sizeof(users());
        int lv = query("gift_level");
        mapping tob, gob, *gls = ({});
        string tname;
        
        set("send_items_count", 0);
        foreach (gob in giftlists) {
                if (lv <= gob["level"]) {
                        tob = copy(gob);
                        tname = tob["file"];
                        if (!tname || tname =="") {
                                if (tob["id"]=="dtzb1")
                                        tname = BRED HIW "������ʯ" NOR;
                                else if (tob["id"]=="dtzb2")
                                        tname = HIY "��˵��ʯ" NOR;
                        } else {
                                tname = load_object(tname)->name();
                        }
                        tob += (["name":tname]);
                        tob["amount"] = to_int(tob["amount"] * (sizeu / 100.00));//wiz startʱ���������Ϊ���ŵı�����
                        if (tob["amount"]<1) tob["amount"] = 1;
                        addn("send_items_count", tob["amount"]);
                        gls += ({tob});
                }
        }
        
        set("gift_items", gls);
}

int send_giftlists()
{
        object usr, *can_send_users = ({});
        int userscount = 0, rday, rlv, aflag, isends = SEND_NUM;
        mapping gob, *gls;
        object tob;
        string msg, tname;
        int i, rate, totalrate, rndrate, *rates;
                
        gls = query("gift_items");
        if (undefinedp(gls) || !gls || !sizeof(gls)) {//�����Ѿ�����
                delete("start_at_time");
                return 1;
        }
                
        rday = query("gift_require_onlineday") * 86400;
        rlv = query("gift_require_level");

        foreach (usr in users()) {
                if (!playerp(usr)) continue;
                if (!interactive(usr)) continue;
                if (wizardp(usr)) continue; 
                if (query("online_time", usr) < rday) continue;
                if (query("level", usr) < rlv) continue;
                userscount ++;
                aflag = query("all_users/" + query("id", usr));
                if (aflag) {
                        set("all_users/" + query("id", usr), aflag - 1);
                } else {
                        can_send_users += ({usr});
                }
        }
        
        while (isends) {
                if (!sizeof(can_send_users)) break;
                usr = can_send_users[random(sizeof(can_send_users))];
                if (!sizeof(gls)) break;
                //gob = gls[random(sizeof(gls))];
                
                //Բ��
                        totalrate = 0;
                        rates = ({});
                        for(i=0; i<sizeof(gls); i++) {
                                rate = gls[i]["amount"];
                                totalrate += rate;
                                rates += ({rate});
                        }
                        rndrate = random(totalrate);
                        totalrate = 0;

                        for(i=0; i<sizeof(rates); i++) {
                                //write("totalrate:" + (string)totalrate + "\n");
                                if (rndrate >= totalrate && rndrate < (totalrate + rates[i])) {
                                        gob = gls[i];
                                        //write(HIY + "rndrate:" + (string)rndrate + "<" + (string)(totalrate + rates[i]) + "\n" + NOR);
                                        break;
                                }
                                totalrate += rates[i];
                        }

                //DEBUG_CHANNEL(NOR + HIG + "  --��" + (string)isends + "��: \n" + NOR);
                isends--;
                if (usr && gob && objectp(usr) && mapp(gob)) {
                        can_send_users -= ({usr});
                        addn("all_users/" + query("id", usr), userscount / SEND_NUM / 2);
                        gob["amount"] -= 1;

                        tname = gob["file"];
                        if (!tname || tname =="") {
                                if (gob["id"]=="dtzb1")
                                        tob = EQUIPMENT_D->create_dynamic("", 100, 600);
                                else if (gob["id"]=="dtzb2")
                                        tob = EQUIPMENT_D->create_dynamic("", 80, 500);
                        } else {
                                tob = new(tname);
                                if (gob["id"]=="wxts") {
                                        set("no_open_msg", 1, tob);
                                        tob->do_open(query("id", tob));
                                }
                                if (gob["id"]=="taozhuang") {
                                        set("bindable", 2, tob);
                                }
                                if (gob["id"]=="ntb") {
                                        log_file("static/yangyong3",sprintf("%s ����֮�� -> ��Ԫ�䶯��;��, �����( %s )\n",TIME_D->replace_ctime(time()), query("id", usr)));
                                }
                        }
                        
                        tname = NOR + (
                                        (query("colorname", tob)) ? query("colorname", tob) : query("name", tob)
                                        ) + NOR;
                                        //NOR + "(" + query("id", tob) + ")" + NOR;
                                        
                        if (tob && tob->move(usr)) {
                                //if (!msg) msg = NOR + HIG + query("name", usr) + "(" + query("id", usr) + ")" + "�õ�" + tname + NOR;
                                //else msg += "��" + NOR + HIG + query("name", usr) + "(" + query("id", usr) + ")" + "�õ�" + tname + NOR;
                                if (!msg) msg = NOR + HIG + query("name", usr) + "�õ�" + tname + NOR;
                                else msg += "��" + NOR + HIG + query("name", usr) + "�õ�" + tname + NOR;
                                tell_object(usr, NOR + HIG + "������" + name() + NOR + HIG + "���͵�" + tname + NOR + HIG + "��" + HIK + "    ( tune news�ɴ�Ƶ�� )\n" + NOR);
                        } else {
                                destruct(tob); 
                        }
                        //DEBUG_CHANNEL(NOR + query("id",usr) + "���" + gob["name"] + "\n ʣ�ࣺ" + (string)gob["amount"] + "��\n" + NOR);
                        if (!gob["amount"]) {
                                //DEBUG_CHANNEL(NOR + HIY + ">>>ע��" + gob["name"] + "\n" + NOR);
                                gls -= ({gob});
                        }
                        
                        continue;
                }
        }
        
        if (msg) post_channel(name() + NOR + HIC + "һˢ������" + chinese_number(SEND_NUM) + "���Ƕ����汦�׷�׹�䡣\n" + sort_msg("    " + msg + "��\n",100));
        
        set("gift_items", gls);
        return 1;
}

string query_giftlists()
{
        string msg = "";
        mapping gob, *gls = query("gift_items");
        foreach (gob in gls) {
                msg += NOR + gob["name"] + NOR + WHT + "(" + (string)(gob["amount"]) + "��) " + NOR;
        }
        return sort_msg(msg, 60);
}

string long()
{
        string msg;
        int start_time = query("start_at_time");
        object me = this_player();
        
        if (query("look_time") > time() && wiz_level(me) < 6) {
                return query("longx") + HIK + "Χ�۵���̫�࣬��Ȼ���ټ��ɡ�\n" + NOR;
        }
        set("look_time", time() + 3 + random(3));
        msg = query("longx");
        if (query("qqgroup/gift")) {// && query("qqgroup/keys") && sizeof(query("qqgroup/keys"))) {
                if (query("gf3_flag")) 
                        msg += HIG "(�������wiz�Ǽ���QQ�ţ�����ȡ" + query("qqgroup/giftname") + HIG + "�����룺input ���QQ��) " HIK + "(ע�⸺��)\n" + NOR;
                else
                        msg += HIG "(������QQ�������ţ�����ȡ" + query("qqgroup/giftname") + HIG + "�����룺input ���) " HIK + "(ʣ��" + HIY + (string)sizeof(query("qqgroup/keys")) + HIK + "����ע�⸺��)\n" + NOR;
        }
        if (start_time) {
                if (start_time > time()) {
                        msg += NOR + " �ɽ綨�ڡ�" + (string)((start_time - time()) / 60) + "�����Ӻ������������͸�������ң������嵥���£�\n" + NOR;
                } else {
                        msg += NOR + " �ɽ�Ŀǰ�����ɷ����������͸�������ң�ʣ��������嵥���£�\n" + NOR;
                }
                msg += query_giftlists() + "\n" + NOR;
        } else {
                msg += NOR + "(Ŀǰ�ɽ�û���ɷ�����ļƻ���)\n" + NOR;
        }
        if (wiz_level(me) > 5) msg += HIK + "(���н���ʦ�ɼ�) - ָ�<tname|tlevel|trequire|tstart  qqaddkey|qqstart \n gf3add(qq,id)|qqstart|gf3start|gf3stop>\n" + NOR;
        return msg;
}

int query_autoload() { return 0; }
int clean_up() { return 1; }

void create()
{
        set_name(NOR BWHT YEL "����" CYN "֮" GRN "��" NOR, ({ "lucky tree" }));
        set_weight(100000000000);
                set("longx", NOR HIW "���Ǻ�����ֲ�İ��������֦ͷ������" + chinese_number(SEND_NUM) + "ֻ" NOR YEL "������" HIW 
                        "�����ǳ���\n���Ĵ��첻ͣ���������ź������鱦���������Ŀ�����ۻ����ҡ�\n" NOR);
                set("unit", "��");
                set("value", 1);
                set("no_uget", 1);
                set("no_drop", 1);
                set("no_give", 1);
                set("no_sell", 1);
                set("no_get", 1);
                set("no_steal", 1);
                set("no_beg", 1);
                set("no_put", 1);
                set("no_store", 1);
                
                set("unique", 1);
                set("no_pawn", 1);

                                set("gift_level", 4);//Ĭ�Ϸ���ͼ�����
                                set("gift_delay", 600);//Ĭ��10�����緢һ�Σ�ÿСʱ6�Σ�����̫ˢ��
                                set("gift_require_level", R_LEVEL);
                                set("gift_require_onlineday", R_ONLINEDAY);
                                
                set_heart_beat(60);
                        setup();
}        

void post_channel(string arg)
{
        //DEBUG_CHANNEL(arg);
        CHANNEL_D->channel_broadcast("news", arg);
}

int do_tname(string arg)
{
        if (!arg) return notify_fail(NOR "���������������Ϊʲô������<tname ʥ��>\n" NOR);
        set_name(NOR + BWHT + YEL + arg + CYN + "֮" + GRN + "��" + NOR, ({ "lucky tree" }));
        write("ok\n");
        return 1;
}

int do_tlevel(string arg)
{
        int lv;
        if( !arg || sscanf(arg, "%d", lv) != 1 ) lv = 4;
        if (lv < 1) lv = 1;
        if (lv > 4) lv = 4;
        set("gift_level", lv);
        if (lv == 1)            write("����������ߵ�����ȼ���\n");
        else if (lv == 2)       write("�����������ϵ�����ȼ���\n");
        else if (lv == 3)       write("����������ͨ������ȼ���\n");
        else                            write("����������͵�����ȼ���\n");
        return 1;
}

int do_tdelay(string arg)
{
        int idelay;
        if( !arg || sscanf(arg, "%d", idelay) != 1 ) idelay = 600;
        if (idelay < 60) idelay = 60;
        if (idelay > 3600) idelay = 3600;
        set("gift_delay", idelay);
        write("��������ÿ��" + (string)(idelay / 60) + "�����緢һ�����\n");
        return 1;
}

int do_tstart(string arg)
{
        int idelay;
        if( !arg || sscanf(arg, "%d", idelay) != 1 ) 
                return notify_fail(NOR "�������Ժ�ʼ�������< ָ���ʽ��tstart Сʱ��(����1) >\n" NOR);
        if (idelay < 1) idelay = 1;
        set("start_at_time", time() + idelay * 3600 + 61);
        set_giftlists();
        write("����������" + (string)(idelay) + "Сʱ��ʼ�������� (look lucky tree���Ի����Ϣ����ȡ��������tcancelָ��)��\n");
        return 1;
}

int do_tcancel()
{
        object me = this_player();
        delete("start_at_time");
        post_channel( NOR + HIW + query("name", me) + NOR + HIW + "ȡ��" + query("name") + NOR + HIW + "��������ļƻ��ˡ�\n" + NOR );
        write("��ȡ��������ķ��͡�\n");
        return 1;
}

int do_trequire(string arg)
{
        int ilv, iday;
        if( !arg || sscanf(arg, "%d %d", iday, ilv) != 2 ) 
                return notify_fail(NOR "�����������߶����죬�ȼ����ٴﵽ���ټ�����Ҳ��ܻ�ã�< ָ���ʽ��do_trequire ���� �ȼ��� >\n" NOR);
        if (ilv < 0) ilv = 0;
        if (iday < 0) iday = 0;
        set("gift_require_level", ilv);
        set("gift_require_onlineday", iday);
        write("ok��\n");
        return 1;
}

int do_qqstart(string arg)
{
        object ob;
        if( !arg) 
                return notify_fail(NOR "����ͨ��QQȺ��ʲô���arg����Ϊ����clone����Ʒ�ļ���\n" NOR);
        ob = new(arg);  
        if (!ob || !objectp(ob))        
                return notify_fail(NOR "arg����Ϊ����clone����Ʒ�ļ���\n" NOR);
        set("qqgroup/gift", arg);
        set("qqgroup/giftname", NOR + query("name", ob) + NOR);
        write(NOR + "������ƷΪ" + query("name", ob) + NOR + "ok��\n");
        return 1;       
}

int do_qqaddkey(string arg)
{
        string *sa;

        if( !arg) 
                return notify_fail(NOR "�������ʲô������ţ�arg����Ϊ�ִ����ִ����飬�����м���,������\n" NOR);
                
        sa = explode( arg, "," );
        set("qqgroup/keys", sa + (query("qqgroup/keys") ? query("qqgroup/keys") : ({})) );
        //write( NOR CYN + implode(query("qqgroup/keys"), ",") + "\n" + NOR);
        write("ok��\n");
        return 1;
}

void remove_qqkey(string arg)
{
        if (!query("qqgroup/keys")) return;
        set( "qqgroup/keys", query("qqgroup/keys") - ({arg}) );
}

int do_input(string arg)
{
        int i;
        object me = this_player();
        if( me->is_busy() )
        {
                write(NOR BUSY_MESSAGE NOR);
                return 1;
        }
        if (!query("qqgroup/gift")) {
                        write(NOR "Ŀǰû���ɷ����\n" NOR);
                        return 1;
        }
        if( !arg || sscanf(arg, "%d", i) != 1) 
                return 0;
        if (query("gf3_flag")) {
                if (!gf3query(arg)) {
                        me->start_busy(15);
                        return 1;
                }
        } else {
                if (!query("qqgroup/keys")) 
                        return 0;
                if (!sizeof(query("qqgroup/keys"))) 
                        return 0;
                if (member_array(arg, query("qqgroup/keys")) == -1)
                {
                        write(NOR "����Ϲ��ʲô��\n" NOR);
                        me->start_busy(15);
                        return 1;
                }
                remove_qqkey(arg);
        }
        CHANNEL_D->channel_broadcast("chat",  (NOR + HIC + query("name",me) + NOR + HIC + "(" + query("id",me) + NOR + HIC + 
                ((query("gf3_flag")) ? ("_QQ" + query_temp("gf3_qq", me)) : "") +")�������������" + query("qqgroup/giftname") + NOR + HIC + "��\n" + NOR) );
        write(NOR "������" + query("qqgroup/giftname") + "��\n" NOR);
        new(query("qqgroup/gift"))->move(me, 1);
        log_file("static/luckytreeqq",sprintf("%s " + query("qqgroup/giftname") + ", �����( %s )\n",TIME_D->replace_ctime(time()), query("id", me)));
        return 1;
}

//gift3
mapping dt = ([]);

int do_save(mapping val)
{
        string rvl;
        string s;
        dt = ([]);

        if (file_size(__DIR__"luckytreedata.o")>0) {
                s = read_file(__DIR__"luckytreedata.o");
                dt = restore_variable(s);
        }
        dt = val;
        rvl = save_variable(dt);
        return write_file(__DIR__"luckytreedata.o", rvl, 1);
}

mixed do_load()
{
        string s;
        dt = ([]);

        if (file_size(__DIR__"luckytreedata.o")>0) {
                s = read_file(__DIR__"luckytreedata.o");
                dt = restore_variable(s);
        }
        return dt;
}

int do_gf3add(string arg)
{
        string qq, idname;
        if( !arg || sscanf(arg, "%s %s", qq, idname) != 2)  {
                return notify_fail(NOR "������ôע�᣿< ָ���ʽ��gf3add qq��(û��qq�Ŵ˴�Ҳ��д���id) id>\n" NOR);
        }
        dt[qq] = (["id" : idname, "lasttime" : 1]);
        //dt["gf3"] += ([qq : (["id" : idname, "lasttime" : 1]) ]);
        do_save(dt);
        write("ok\n");
        return 1;
}

int gf3query2(string qq)
{
        dt = do_load();
        if (!dt || !sizeof(dt)) return 0;
        if (member_array(qq, keys(dt)) == -1) return 0;
        return dt[qq]["lasttime"];
}

int gf3query(string qq)
{
        int lasttime;
        object me = this_player();
        
        if (!query("gf3_flag")) {
                write(NOR "Ŀǰû���ɷ����\n" NOR);
                return 0;
        }
        lasttime = gf3query2(qq);
        if (!lasttime) {
                write(NOR "���QQ�ʺ�û�еǼǹ���\n" NOR);
                return 0;
        }
        if (dt[qq]["id"] != query("id", me)) {
                write(NOR "���QQ������������ȡ���\n" NOR);
                return 0;
        }
        if (lasttime == (time() / 86400)) {
                write(NOR "�����Ѿ���ȡ�������ˡ�\n" NOR);
                return 0;
        }
        dt[qq] = (["id" : query("id", me), "lasttime" : (time() / 86400)]);
        do_save(dt);
        set_temp("gf3_qq", qq, me);
        write(NOR "��ȡ����ɹ���\n" NOR);
        return 1;
}

int do_gf3start() {
        dt = do_load();
        set("gf3_flag", 1);
        write(query("gf3_flag") + "\n");
        return 1;
}

int do_gf3stop() {
        set("gf3_flag", 0);
        write(query("gf3_flag") + "\n");
        return 1;
}

void init()
{
        object me = this_player();
        add_action("do_input", "input"); 
        if (query("id", me)==query("grant_id"))
                add_action("do_gf3add", "gf3add"); 
        if (!playerp(me) || wiz_level(me) < 6) return;
        add_action("do_tname", "tname"); 
        add_action("do_tlevel", "tlevel"); 
        add_action("do_trequire", "trequire"); 
        add_action("do_tdelay", "tdelay"); 
        add_action("do_tstart", "tstart"); 
        add_action("do_tcancel", "tcancel"); 
        add_action("do_qqaddkey", "qqaddkey"); 
        add_action("do_qqstart", "qqstart"); 
        add_action("do_gf3add", "gf3add"); 
        add_action("do_gf3start", "gf3start"); 
        add_action("do_gf3stop", "gf3stop"); 
}

void heart_beat()
{
        object where = environment();
        object me = this_object();
        int fstart, ct, start_time = query("start_at_time");
        int yjtime;

        if (!start_time) return;
        if (!where || !objectp(where) || !where->is_room()) return;
        fstart = start_time > time();
        if (fstart) {
                yjtime = query("send_items_count") / SEND_NUM * (query("gift_delay")+1) / 3600;
                if (yjtime<1) yjtime = 1;
                ct = start_time - time();
                ct /= 60;
                if (ct >= 60 && (ct % 60) == 0) {
                        ct /= 60;
                        //�ɶ��Ц���ǣ��Լ�����newsƵ������ֻ����ȥchatƵ��ˢ
                        CHANNEL_D->channel_broadcast("chat", ( NOR + HIC + query("name") + NOR + HIC + "(��ǧ԰)����" + chinese_number(ct) + NOR + HIC + 
                                        "Сʱ�󣬿�ʼ����" + chinese_number(yjtime) + "Сʱ����(�������Ƶ��)�������߳�" + chinese_number(query("gift_require_onlineday")) + "�졢�ȼ���" + chinese_number(query("gift_require_level")) + "������ҡ�\n" + NOR ));
                } else if (ct != 0) {
                        if ( ((ct<31) && ((ct%5)==0)) || (ct<5) ) {
                                post_channel( NOR + HIG + query("name") + NOR + HIG + "(��ǧ԰)����" + chinese_number(ct) + NOR + HIG + 
                                        "���Ӻ󣬿�ʼ����" + chinese_number(yjtime) + "Сʱ���񣬸����߳�" + chinese_number(query("gift_require_onlineday")) + "�졢�ȼ���" + chinese_number(query("gift_require_level")) + "������ҡ�\n" + NOR );
                        }
                }
                return;
        }
        if ( query("send_at_time") <= time() ) {
                set("send_at_time", time() + query("gift_delay"));
                send_giftlists();
        }
}



