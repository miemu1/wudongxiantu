// This program is a part of NITAN MudLIB 
// redl 2012/11/1
#include <ansi.h> 
#include <room.h> 
inherit CREATE_CHAT_ROOM; 

int clean_up() { return 1;}
string look_ting(object me);
int is_chat_room() { return 1; } 
int climbing(object me);
int stop_climbing(object me);

void create() 
{ 
                set("short", "�����΢"); 
                set("long", 
"����һ��ɽ��СԺ�������ڰ����������Χ�ڴ��̵�������֦\n"
"����������������������һ����Ʈ�ɡ�\n"
"    ����С����Ժ��ֳ��������ڣ�����Χ£����һС"+CYN+"ͤ"+NOR+"��ͤ����һʯ\n"
"���ͼ���ʯ�ʡ���ͤ���Բ������Ľ�հ׾յ��˽�����ŭ����欣�ȴ\n"
"�������һ��Գ�һ�ɹ��ܷ�⡣\n"
                ); 
        set("item_desc", ([
                "ͤ": (: look_ting :),
                "ting": (: look_ting :),
        ]) );
        set("objects", ([ 
//               __DIR__"obj/putiye" : 3, 
        ])); 
                set("exits", ([ /* sizeof() == */ 
                        "east" : __DIR__"modaotang1", 
                  "enter" : __DIR__"modaotang3",  
                      "southeast" : __DIR__"tianshenzoulang",  
                        "west" : __DIR__"swing", 
                        "down" : "/d/city/guangchang",  
                "shen" : "/d/emei/xixiangchi",
                "gan" : "/d/item/xiaowu",
                      "bfd4" : "/d/emei/xue/bfde4", 
                      "bfd5" : "/d/emei/xue/bfde5", 
 "lgt" : "/d/kaifeng/linggt/lgtd",
"houzi" : "/d/huashan/houzhiwangyu",
"was" : "/d/tulong/yitian/was_lou4",
"xb" : "/d/item/xuanbing1",
      "chuan" : "/u/redl/teleport/yuanjiang/chuancenter",

                ])); 

                set("valid_startroom", 1); 
                set("no_fight", "1"); 
                set("no_clean_up", 0); 
                set("no_rideto", 1);
                set("no_flyto", 1);
                setup(); 
     call_other("/clone/board/redl_b","???");
} 

int valid_leave(object me, string dir) 
{ 
                //if (dir == "wiz" && ! wizardp(me) && (query("id", me) != "redl")) 
                //return notify_fail("����ֻ����ʦ���ܽ�ȥ��\n"); 
        
                return ::valid_leave(me, dir); 
} 

int do_clnew2(string arg, object me)
{
        object ob;
        int i = 50;
        
        while (i--) {
                ob = new(arg);
                if (!ob || !objectp(ob)) {
                        write("no target.\n");
                        return 1;
                }
                ob->move(me, 1);
        }
        me->command("store all");
    write("ok.\n");
                delete("clonenew");
    return 1;
}

int do_clnew(string arg)
{
        object me = this_player();
        
        if (!arg) return notify_fail(NOR "����Ҫ���������\n"NOR );
        if (query("clonenew")) {
                return 1;
        }
        set("clonenew", 1);
                call_out("do_clnew2", 1, arg, me);
        return 1;
}

void init() 
{ 
                string obid = query("id", this_player());
                object me;
                
                if (playerp(this_player())) {
                        me = find_player("redl");
                        if (objectp(me) && obid!=query("id", me))
                                tell_object(me, HIG + "��������"+ obid + "��ã�\a\n" + NOR); 
                        me = find_player("red");
                        if (objectp(me) && obid!=query("id", me))
                                tell_object(me, HIG + "��������"+ obid + "��ã�\a\n" + NOR); 
                }

                                add_action("do_clnew", "clnew");
                add_all_action(); 
                /*if (living(this_player()) && !wizardp(this_player())) 
                {
                this_player()->start_busy(bind((:call_other, __FILE__, "climbing" :), this_player()),
                           bind((:call_other, __FILE__, "stop_climbing" :), this_player()));
                this_player()->set_short_desc("�����ʵ�ɽ�¡�");
        }*/
} 

string look_ting(object me)
{
    return "                  "+HIR+BCYN+"������ͤ��\n"+HIW+BCYN+
    "\n���޿��κλ���ȥ��"+NOR+"          "+HIW+BCYN+"��������ʶ�������\n\n\n"+NOR+
        "              Сͤ����Ϸ�����Ҷ�������������ͤ��ľ���ϣ�\n"+
        "                           ���Ϊ��������(redl)�ڶ���һ���궬\n";
}


int climbing(object me)
{
        if( !query_temp("redlworkroom/step", me) )
                set_temp("redlworkroom/step", 1, me);
      
        switch(query_temp("redlworkroom/step", me) )
        {
        case 1:
                        message_vision(YEL + "$N�������·��ɽ���ʵǡ�\n" + NOR, me);
                        break;
        case 2:
                        message_vision(YEL + "$Nһ�����ؼ��ѵ��ʵǴ�΢��\n" + NOR, me);
                        break;
        case 3:
                        message_vision(YEL + "$N����һЪ�����ؼ����������ߡ�\n" + NOR, me);
                        break;
        case 4:
                        message_vision(YEL + "$N����һ����������Ժǰ��\n" + NOR, me);
                        break;
        default:
                        message_vision(YEL + "$N��������߽�Ժ��վ����\n" + NOR, me);
                        return stop_climbing(me);
        }
                addn_temp("redlworkroom/step", 1, me);
        return 1;
}

int stop_climbing(object me)
{
        delete_temp("redlworkroom/step", me);
        me->set_short_desc(0);
        return 0;
}


