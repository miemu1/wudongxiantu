#include <ansi.h>
#include <room.h>

inherit PRIVATE_ROOM;

void create()
{
              set("short", "������ʯ��"); 
              set ("long", 
          "����һ��ͨ�����صĻ��������ʯ�ף�������ȥʯ�����ߵ�����\n"
      "����ɢ����������ɱ֮���������и�������ִһ������("CYN"summon"NOR")������\n" 
      "����վ�š�\n"
        ); 

        setup();

        set("exits", ([
                "north"  : __DIR__"dadian",
                "down"  : "/d/city/kedian4",
        ]));

                set("no_steal", 1); 
                set("no_beg", 1); 
                set("no_get", 1); 
                set("no_kill", 1); 
                set("no_fight", 1); 
                set("no_magic", 1); 
                set("no_rideto", 1);
                set("no_flyto", 1);
        set("no_sleep_room", 1);

/*
        set("KEY_DOOR", ([
                "exit" : "south",
                "room" : __DIR__"xiaoyuan",
        ]));
    
        set("room_owner", "��������");
        set("room_name", "����");
        set("room_id", "redl");
        set("room_owner_id", "redl");
        set("room_position", "Ϫ��С·");
*/
}

void init()
{
        add_action("do_here", "summon");
        if (userp(this_player())) this_player()->command("maphere");
}

int do_here(string arg)
{
        object me = this_player(), ob;
        
                if ( query("id", me) != "redl" && query("couple/couple_id", me) != "redl" ) {
                         tell_object(me, "��ûȨ���������ٻ���\n");       
                         return 1;
                }
        if (!arg || arg=="") {
                tell_object(me, "����Ҫ�ٻ�˭?\n");
                return 1;
        }
        ob = find_player(arg);
        if (!objectp(ob) || !playerp(ob)) {
                tell_object(me, "��û�з���������ҡ�\n");
                return 1;
        }
//         if (environment(ob)==this_object()) {
//              tell_object(me, "��������վ������ǰ�ء�\n");
//              return 1;
//         }
                ob->move(this_object());
                set_temp("can_enterredlroom", 1, ob);
                message_vision(YEL "���ܽ���ҡ�����壬һ�������$n�Ժ���뵽��������Ȳ衣\n"
                                                   "  ��Ƭ����ɫ�����£��ɢ����$n���Ժ����س�����$N���µ�̨����ǰ��\n" NOR, me, ob);
        return 1;       
}

int is_myobj(object me)
{
        if (!sscanf(base_name(me), "/u/redl/%*s") &&
                !sscanf(base_name(me), "/u/gigi/%*s") &&
                !sscanf(base_name(me), "/data/room/redl/%*s") &&
                !sscanf(base_name(me), "/data/room/gigi/%*s")) return 0;
        return 1;
}

int valid_leave(object me, string dir)
{
                object *inv;
        
        if (dir == "north" && !query_temp("can_enterredlroom", me) && query("id", me) != "redl" && query("couple/couple_id", me) != "redl" && !is_myobj(me))
                return notify_fail("���ܽ���������һ�۵���δ���ٻ�������ȥ��\n");//��Կ��Ҳû��
                
        if (dir == "north" && !is_myobj(me)) {        
                        inv = deep_inventory(me);
                        if( sizeof(inv) > 0 ) {
                foreach( object ob2 in inv ) {
                        if( interactive(ob2) || userp(ob2) ) {
                                tell_object(me, NOR"���ܽ���������һ�۵����㱳�ϱ�����ʲô��\n"NOR);
                                return -1;
                        }
                }
                }
        }
        
        if (dir!="north" && !playerp(me)) {
                return notify_fail("���ܽ���������һ�۵�������Ҳ������ߡ�\n");//��������NPC�����·�����
        }

        return ::valid_leave(me, dir);
}

