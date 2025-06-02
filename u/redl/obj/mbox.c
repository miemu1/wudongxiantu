// This program is a part of NITAN MudLIB 
// redl 2013/5 
// ˽�У�С�ı�����ˢ���͸��Ż�����

#include <ansi.h>
inherit ITEM;


int start_make(object me);
void save_music(string str);

int timeintervals = 3, idx = 0, imax;
string *text = ({});
string qz = "  �� ";

void create()
{
        set_name(WHT "���ֺ�" NOR, ({"music box", "box"}));
        set_weight(1);
                set("longx", WHT"���ǿ�Ĵָ��С��̴ľ����������Ÿ������ĺ��ң����ҵĸ�\n"
                                           "�������һ��С�ɵĹ�����̴ľ�ײ����š�paroles et musique����\n"
                                        HIK"(ָ�mplay�� mmake�� mdelay)\n"NOR);
                set("unit", "��");
                set("material", "silver");
                set("value", 2000000000);
                set("nj", 20); 
                set("set_data", 1); 
                set("auto_load", 1); 
}

string long()
{
        string *t = query("content");
        int i = sizeof(t);
        if (i < 1) return query("longx") + qz + "�հס���\n" + NOR; 
                else return query("longx") + qz + t[0] + "\n" + NOR; 
}

int init()
{
        add_action("do_make", "mmake");
        add_action("do_delay", "mdelay");   
        add_action("do_play", "mplay");   
}

int do_delay(string arg)
{
        if (!arg && arg!="+" && arg!="-") return notify_fail("��ʽ��mdelay + ���� mdelay -\n"); 
        if (query("timeintervals")) timeintervals = query("timeintervals");
        if (arg=="+") {
                if (timeintervals<9) {
                        timeintervals += 1;
                set("timeintervals", timeintervals);
                }
                return notify_fail("��ǰ���ż����"+chinese_number(timeintervals)+"��\n"); 
        }
                if (timeintervals>1) {
                        timeintervals -= 1;
                set("timeintervals", timeintervals);
                }
                return notify_fail("��ǰ���ż����"+chinese_number(timeintervals)+"��\n"); 
}


int do_make(string arg)
{
        object me, ob;
        me = this_player();
        ob = this_object();
        //if( !arg && arg!="music box" && arg!="box") return 0;

    message_vision(YEL"$N�ó�һ������ɫ��" + query("name") + YEL "..\n"NOR,me);
    start_make(me);
    return 1;
}


int start_make(object me)
{
        //write("Ϊ��дһ�׸���:\n");
        me->edit( (: save_music :) );
        return 1;
}

void save_music(string str)
{
        if (strlen(str)>8192) {
                write(NOR "̫��̫���ˡ�\n");
                return;
        }
        message_vision(YEL"$N��" + query("name") + YEL "��¼����һ�׸衣\n"NOR, this_player());
                text = explode( str, sprintf("%c", 10) );
        set("content", text);
}

int do_play(string arg)
{
        object me, ob;
        me = this_player();
        ob = this_object();
        //if( !arg && arg!="music box" && arg!="box") return 0;
        if (query_temp("starting")) return notify_fail("��������Ѿ��ڲ��������ˡ�\n"); 
        if (query("nj") < 1) return notify_fail("��������Ѿ����ˡ�\n"); 
        
        addn("nj", -1);
        addn("value", -100000000);
        
        text = query("content");
        imax = sizeof(text);
        if (imax < 1) return notify_fail("������ mmake ¼��\n"); 
        
    message_vision(YEL"$N�ó�һ��"WHT"����"YEL"�����ҡ��������\n"
                                "һ���ö������ĸ���������������Ķ���...\n"NOR,me);
    idx = 0;
    if (query("timeintervals")) timeintervals = query("timeintervals");
    set_temp("starting", 1);
    set("no_give", "�������ֲ������...");
    set("no_store", "�������ֲ������...");
    set("no_drop", "�������ֲ������...");
    set("no_sell", "�������ֲ������...");
    set("no_steal", "�������ֲ������...");
    set("no_beg", "�������ֲ������...");
    //message_vision(NOR, me);
    call_out("start_play", timeintervals, me);
    return 1;
}

int start_play(object me)
{
        if (idx < imax) {
                message_vision(NOR + HIK + qz + NOR + text[idx] + "\n" + NOR, me);
                call_out("start_play", timeintervals, me);
        }
                else {
                        //message_vision(NOR + HIK + qz + NOR + "(ending...)\n" + NOR, me);
                    delete("no_give");
                delete("no_store");
                delete("no_drop");
                delete("no_sell");
                delete("no_steal");
                delete("no_beg");
                        delete_temp("starting");
                    message_vision(YEL"$Nֹͣ��ҡ��������һ�ֿ���ĸо�ӿ����ͷ��\n"NOR,me);
                    tell_object(me, NOR "ʣ�ಥ�Ŵ�����" + chinese_number(query("nj")) + "�Ρ�\n" NOR);
                }
        idx += 1;
        return 1;
}



