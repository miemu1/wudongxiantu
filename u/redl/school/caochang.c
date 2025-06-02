// This program is a part of NITAN MudLIB 
// redl 2013/8
#include <ansi.h> 
#include <room.h> 
inherit ROOM; 

#define BONUS_EXP 36000
#define BONUS_IMPROVE_SKILL 10000

int clean_up() { return 1;}

void create()
{
        set("short", "ѧ�òٳ�");
        set("long", 
"�ٳ���ǰ���߸�������һ������ɫ����ˣ���˵Ķ�����һ�����޵�\n"
"���Ǻ��죬�������죬ӳ�Ű��ƣ��Եø���ׯ�ϡ��ٳ��Ա��и�С������\n"
"�����������ƣ�Ұ����ء���\n");
                set("outdoors", "yangzhou");
                set("exits",([ /* sizeof() == 1 */
                        "south" : __DIR__"gate",
                        "north" : __DIR__"jiaoshi",
                ]));

        set("no_dazuo",1);
        set("no_kill",1);
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);         
                set("no_rideto", 1);
                set("no_flyto", 1);
                set("no_magic", 1); 
        set("no_sleep_room", 1); 
        
        setup();
}


int filter_skill(string sk, object me)
{
        if (!me->can_improve_skill(sk)) return 0;
        if (SKILL_D(sk)->type() != "martial") return 0;
        return 1;
}

int do_giftbaby(object me, string msg, int p)
{
        int r;
        r = BONUS_EXP + random(BONUS_EXP/10);
        if (!p) p = 100;
        r = r * p / 100;
        call_other(GIFT_D, "bonus", me, ([ "exp":r, "pot":r/3, "prompt":"����"+msg]));
        addn("experience", r/10, me);
        message_vision(NOR + "$N" + HIG + "��" + msg + "�����" + chinese_number(r) + "����Ϊ��" + chinese_number(r/3) + "��Ǳ�ܡ�" + chinese_number(r/10) + "����ᡣ\n" + NOR, me);
        return 1;
}

int do_giftbaby2(object me, string msg, int p)
{
        int r, lv, imp;
        string *ks;
        lv = query("level", me);
        if (lv < 1) lv = 1;
        if (lv > 100) lv = 100;
        imp = (BONUS_IMPROVE_SKILL + random(BONUS_IMPROVE_SKILL/10)) * lv / 5;
        if (!p) p = 100;
        imp = imp * p / 100;
                                if (!me->query_skills() || !sizeof(me->query_skills())) {
                                        me->improve_skill("dodge", 1000);
                                        me->improve_skill("force", 1000);
                                        me->improve_skill("parry", 1000);
                                        me->improve_skill("unarmed", 1000);
                                        me->improve_skill("cuff", 1000);
                                        me->improve_skill("hand", 1000);
                                        me->improve_skill("claw", 1000);
                                        me->improve_skill("strike", 1000);
                                }
                        ks = filter_array(keys(me->query_skills()), (: filter_skill :), me);
                        if (r = sizeof(ks))
                        {
                                r = random(r);
                                me->improve_skill(ks[r], imp);
                                message_vision(NOR + "$N" + HIG + "��" + msg + "�ԡ�" + to_chinese(ks[r]) + "����������\n" + NOR, me);
                        }
        return 1;
}

void do_rndmove(object baby, string str)
{
        object room;
        
        if (!baby || !objectp(baby)) return;
        room = environment(baby);
        if (!room || base_name(room)!=str) return;
        if (!query_temp("school/init", baby)) return;
        
        if (baby->is_busy()) {
                call_out("do_rndmove", 2, baby, str);
                return;
        }
        
        delete_temp("school/init", baby);
        
        if (!random(5)) {
                if (!random(25)) {
                        baby->command("go north");
                } else {
                        baby->command("go south");
                }
                return;
        } else {
                switch (random(10)) {
                        case 0:
                                message_vision(CYN + "$N" + CYN + "��ͨ~~һ������������ȥ�ˣ�����ð��ͷ���ϰ�������ץ���������㡣\n" + NOR, baby);
                                if (query_temp("school/play", baby)<10) {
                                        addn_temp("school/play", 3 + random(2), baby);
                                        break;
                                }
                                set_temp("school/play", 1, baby);
                                do_giftbaby(baby, "��Ϸ������", 100);
                                break;
                        case 1:
                                message_vision(CYN + "$N" + CYN + "�ó�һ��С���ڵ�����ѽ�ˣ���Ȼ�ڳ�һ�����ϵ�����\n" + NOR, baby);
                                if (query_temp("school/play", baby)<13) {
                                        addn_temp("school/play", 3 + random(2), baby);
                                        break;
                                }
                                set_temp("school/play", 1, baby);
                                do_giftbaby2(baby, "��Ϸ������", 100);
                                break;
                        case 2:
                                baby->command("ruffle Ƥ��");
                                addn_temp("school/play", 1, baby);
                                break;
                        case 3:
                                baby->command("zaocao");
                                addn_temp("school/play", 1, baby);
                                break;
                        case 4:
                                baby->command("roll2");
                                addn_temp("school/play", 1 + random(2), baby);
                                break;
                        case 5:
                                baby->command("jump " + query("id", baby));
                                addn_temp("school/play", 1 + random(2), baby);
                                break;
                        case 6:
                                baby->command("roll " + query("id", baby) + " ƨ��");
                                addn_temp("school/play", 1 + random(2), baby);
                                break;
                        case 7:
                                message_vision(CYN + "$N" + CYN + "�����һ��˳�����������ȥ���ֿ��ټн�˫�Ȼ������󺰵�����ˬ����ˬ..\n" + NOR, baby);
                                addn_temp("school/play", 3 + random(2), baby);
                                break;
                        case 8:
                                message_vision(CYN + "$N" + CYN + "�����һ��˳�����������ȥ������˶����ͳ�һ���񵰣�OMG...\n" + NOR, baby);
                                addn_temp("school/play", 3 + random(2), baby);
                                break;
                        default:
                                baby->command("think ����һ������ʲô�أ�");
                                break;
                }               

                set_temp("school/init", 1, baby);
                call_out("do_rndmove", 8 + random(2), baby, str);
        }
}

void init()
{
        object ob = this_player();
        if (base_name(ob)=="/clone/user/baby") {
                ob->command("halt");
                ob->command("think ����һ������ʲô�أ�");
                
                set_temp("school/init", 1, ob);
                call_out("do_rndmove", random(6) + 10, ob, base_name(this_object()));
        }
}

int valid_leave(object me, string dir)
{
        if (!playerp(me) && dir == "north") {
                if (base_name(me)!="/clone/user/baby") {
                        me->start_busy(35+random(26));
                        return 0;
                }
                
                if (!query_temp("school/pay", me)) {
                        me->start_busy(random(6) + 10);
                        message_vision(YEL "���Ŵ��������������ܹ���һ����ס$N" YEL "�������ţ����㸸ĸ������ѧ����ȥ�����Ͽ�...\n" NOR, me);
                        set_temp("school/init", 1, me);
                        call_out("do_rndmove", 2, me, base_name(this_object()));
                        return 0;
                }
        }
        
        return ::valid_leave(me, dir);
}


  
