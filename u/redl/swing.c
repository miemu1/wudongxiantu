/*
 * TLBB MUDLIB
 * $Header: /home/mud/cvsroot/tlbbmud/tlbb/tlbb_mudlib/t/ly/swing.c,v 1.4 2000/04/15 05:30:46 mud Exp $
 */
 
// Room: /t/ly/swing.c

#include <ansi.h>
#include <room.h>
inherit ROOM;

string look_swing(object me);
string *high_msg = ({
        "�ŵü������С�����������\n",
        "��ɫ�԰ף����ŵ����������ҳ��ˡ�\n",
        "ֻ����ͷ���ۻ�������ˤ������\n",
        "���ŸϽ�ͣ������\n",
        "�������š�����氡����\n",
        "���������������¡���������\n",
});
string *mid_msg = ({
        "��С�ˬ������̼�����\n",
        "�˷ܵ�����ͨ�죬�����ǲ������ۡ�\n",
        "�ƺ������ò���񫣬�����ٸ�һЩ��\n",
        "һ�������ɵ����ӡ�\n",
        "���ŵĺ��������ˡ�\n",
        "������Ц����û��ô���˹���\n",
});
string *low_msg = ({
        "���˵Ľи���ͣ��\n",
        "�˷ܵ�����ǧ�������㵸��Ҳ����ˤ������\n",
        "�����е�ͷ�Σ����������Լ�֡�\n",
        "����������ͯ��ʱ�⡣\n",
        "�о��������磬�����ٸ�һ�㡣\n",
        "����ǧ��վ������������ʾ�߳��ļ�����\n",
});

void create()
{
        set("short", "��ǧ԰");
        set("long", 
        "һ�������Ļ�԰���Ӳݴ�������Ҷ�ͷס������һ��Сʯ����\n"
        "����ʯ�ʡ��ұ������ô��������м����һ��"+CYN"��ǧ"NOR+"��һ��紵����\n"
        "��Ҷ�ڿ��з��裬���������ֹ�����ǧҲ���ᵴ���������·���\n"
        "˵�����յļ��䡣\n"
        );
        set("exits", ([ /* sizeof() == 2 */
                        "east" : __DIR__"workroom",
                        "west" : "/u/gigi/workroom",
                        "south" : "/u/redl/private_room/houyuan",  
                        "down" : "/d/city/swing",
]));
        set("item_desc", ([
                "��ǧ": (: look_swing :),
                "swing": (: look_swing :),
        ]) );
        set("sleep_room", 1);
        set("no_fight", 1);
        set("no_magic", 1);
        set("no_clean_up", 0);

        setup();
        
}

string look_swing(object me)
{
        return "����һ����������͵���ǧ(swing)����Ȼ�Ѿ������ã�\n������������ʵ����������ȥ(sit)���ԣ�\nҲ���Ա����İ���������ȥ(lift)��\n";
}

void init()
{
        add_action("do_sit", "sit");
                add_action("do_lift", "lift");
        add_action("do_dang", "dang");
        add_action("do_push", "push");
        add_action("do_down", "down");
}

int do_sit(string arg)
{
        string sitter;
        object me,ob;
        me = this_player();
        if(!arg) {
                message_vision("$N�����˵��ϡ�\n",me);
                return 1;
        }
        if(arg != "swing") return notify_fail("��Ҫ��ʲô��\n");
        if(me->is_fighting()) return notify_fail("һ�ߴ��һ�ߵ���ǧ����û�°ɣ�\n");
        if(me->is_busy()) return notify_fail("����æ�ţ�û�յ���ǧ��\n");
        if(query("marks/sitted")) {
                sitter=query("marks/sitted", this_object());
                ob = present(sitter,environment(me));
                if( (ob) && (query_temp("marks/sitted", ob))){
                        write("��ǧ���Ѿ������ˡ�\n");
                        return 1;
                }
        }
        message_vision("$N��������ǧ���档\n", me);
        write("������Լ�����ǧ(dang)��Ҳ�����ñ�����һ��(push)��\n");
        set("marks/sitted",query("id", me));
        set_temp("marks/sitted", 1, me);
me->set_short_desc("��������ǧ�ϡ�"); 
        return 1;
}

int do_lift()
{
        string sitter;
        object me,ob;
        me = this_player();
        if(query("marks/sitted")) {
                sitter=query("marks/sitted", this_object());
                ob = present(sitter,environment(me));
                if( (ob) && (query_temp("marks/sitted", ob))){
                        write("��ǧ���Ѿ������ˡ�\n");
                        return 1;
                }
        }
        sitter = query("couple/couple_id", me );
        if (!sitter) {
                 write("�㻹û�а��ˡ�\n");
                 return 1;
        }
        ob = present(sitter, environment(me));
        if (!objectp(ob)) {
                 write("���뱧˭����ǧ��\n");
                 return 1;
        }
        if( !ob->is_character() || query("not_living", ob) ) {
                 write("������ˣ��ǲ��ǻ��ˣ�\n");
                 return 1;
        }
        message_vision("$N���ᱧ��$n�ŵ�����ǧ���档\n", me,ob);
        tell_object(ob, "������Լ�����ǧ(dang)��Ҳ�����ñ�����һ��(push)��\n");
        set("marks/sitted",query("id", ob));
        set_temp("marks/sitted", 1, ob);
ob->set_short_desc("��������ǧ�ϡ�"); 
        return 1;
}

int do_dang()
{
        int i;
        object me;
        me = this_player();
        if(me->is_fighting()) return notify_fail("һ�ߴ��һ�ߵ���ǧ����û�°ɣ�\n");
        if(me->is_busy()) return notify_fail("����æ�ţ�û�յ���ǧ��\n");
        i=query_temp("marks/swingm", me);
        if( !query_temp("marks/sitted", me) )
        return notify_fail("�㻹û������ǧ�ϡ�\n");
        if( !query_temp("marks/swingm", me)){
                message_vision("$N����һʹ������ǧ�����ĵ���������\n",me);
                set_temp("marks/swingm", 3, me);
                call_out("swing_left",7,me);
                return 1;
        }
        if( query_temp("marks/swingm", me)>9){
                message_vision("$N������һʹ������ǧ���ķ���������\n",me);
                message_vision(RED"$N����һ�����ȣ�����ǧ�ϵ���������ˤ�˸���ƨ�Ѷ���\n"NOR,me);
                remove_call_out("swing_left");
                remove_call_out("swing_right");
                delete_temp("marks/sitted", me);
                delete_temp("marks/swingm", me);
                delete("marks/sitted", this_object());
me->set_short_desc(0); 

                return 1;
        }
        
        message_vision(YEL"$Nʹ������һ�£���ǧ���ĸ��߸����ˣ�\n"NOR,me);
        i = i + 3;
        set_temp("marks/swingm", i, me);
        remove_call_out("swing_left");
        remove_call_out("swing_right");
        call_out("swing_left",10-i,me);
        return 1;
}

int do_push(string arg)
{
        int i;
        object me,ob;
        me = this_player();
        if(me->is_fighting()) return notify_fail("һ�ߴ��һ�ߵ���ǧ����û�°ɣ�\n");
        if(me->is_busy()) return notify_fail("���Ȱ���ͷ����æ����˵�ɡ�\n");
        if(!arg || !objectp(ob = present(arg, environment(me))))
                return notify_fail("��Ҫ��˭����\n");
        if( arg == query("id", me))return notify_fail("��û���Լ����Լ�����pig...:P\n");
        if( !query_temp("marks/sitted", ob) )
                return notify_fail("�Է�������ǧ�ϣ���û���ơ�\n");
        if(ob->is_fighting()) return notify_fail("һ�ߴ��һ�ߵ���ǧ����û�°ɣ�\n");
        if(ob->is_busy()) return notify_fail("�Է���æ���ء�\n");
        i=query_temp("marks/swingm", ob);
        if( !query_temp("marks/swingm", ob)){
                message_vision(YEL"$N��������$nһ�£���ǧ��������������\n"NOR,me,ob);
                set_temp("marks/swingm", 3, ob);
                call_out("swing_left",7,ob);
                return 1;
        }
        if( query_temp("marks/swingm", ob)>9){
                message_vision("$N��ʹ������$nһ�£���ǧ���ķ���������\n",me,ob);
                message_vision(RED"$N����һ�����ȣ�����ǧ�ϵ���������ˤ�˸���ƨ�Ѷ���\n"NOR,ob);
                remove_call_out("swing_left");
                remove_call_out("swing_right");
                delete_temp("marks/sitted", ob);
                delete_temp("marks/swingm", ob);
                delete("marks/sitted", this_object());
                return 1;
        }
        
        message_vision(YEL"$N����������$nһ�£���ǧ���ĸ��߸����ˣ�\n"NOR,me,ob);
        i = i + 3;
        set_temp("marks/swingm", i, ob);
        remove_call_out("swing_left");
        remove_call_out("swing_right");
        call_out("swing_left",10-i,ob);
        return 1;
}
int do_down()
{
        object me;
        me = this_player();
        if( !query_temp("marks/sitted", me) )
        return notify_fail("�������û�г�·��\n");
        message_vision("$N��ҡ������ǧ�ϱ���������\n",me);
        remove_call_out("swing_left");
        remove_call_out("swing_right");
        delete_temp("marks/sitted", me);
        delete_temp("marks/swingm", me);
        delete("marks/sitted", this_object());
me->set_short_desc(0); 
        return 1;
}

void swing_left(object me)
{
        int i;
        string msg;
        i=query_temp("marks/swingm", me);
        if(i>0) {
                if(i>3) {
                        if(i>6) {
                                msg = "��ǧ��ǰ�����ָ���ֱ��$N"+high_msg[random( sizeof( high_msg ))];
                                message_vision(msg,me);
                                call_out("swing_right",10-i,me);
                                return;
                        }
                        msg = "��ǧ��һ����ǰ��ȥ��$N"+mid_msg[random( sizeof( mid_msg ))];
                        message_vision(msg,me);
                        call_out("swing_right",10-i,me);
                        return;
                }
                msg = "��ǧ������ǰ��ȥ��$N"+low_msg[random( sizeof( low_msg ))];
                message_vision(msg,me);
                call_out("swing_right",10-i,me);
                return;
        }
}

void swing_right(object me)
{
        int i;
        string msg;
        i=query_temp("marks/swingm", me);
        i = i-1;
        if(i<1) {
                message_vision("��ǧ����ͣ��������$N����δ����������ǧ��\n",me);
                delete_temp("marks/sitted", me);
                delete_temp("marks/swingm", me);
                delete("marks/sitted", this_object());
                return;
        }
        set_temp("marks/swingm", i, me);
        if(i>0) {
                if(i>3) {
                        if(i>6) {
                                msg = "��ǧ��󵴵��ֿ����ͣ�$N"+high_msg[random( sizeof( high_msg ))];
                                message_vision(msg,me);
                                call_out("swing_left",10-i,me);
                                return;
                        }
                        msg = "��ǧ�߸ߵ����ȥ��$N"+mid_msg[random( sizeof( mid_msg ))];
                        message_vision(msg,me);
                        call_out("swing_left",10-i,me);
                        return;
                }
                msg = "��ǧ�������ȥ��$N"+low_msg[random( sizeof( low_msg ))];
                message_vision(msg,me);
                call_out("swing_left",10-i,me);
                return;
        }
}

int valid_leave(object me, string dir)
{
        if( query_temp("marks/sitted", me) )
        return notify_fail("����Ҫ����ǧ������(down)�����뿪��\n");
        return ::valid_leave(me, dir);
        return 1;
}

