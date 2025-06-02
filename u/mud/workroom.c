// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <room.h>
inherit CREATE_CHAT_ROOM;

int is_chat_room() { return 1; }
int do_hy(string arg); 
int do_pick();

void create()
{
        set("short", NOR HIW "��" HIK "��" NOR);
        set("long", @LONG
����û�н��칤���ҵ���ʦ����ʱס����������豸�ǳ��򵥣�ֻ��
һЩ������Ʒ��
LONG );

        set("exits", ([ /* sizeof() == 1 */
                "north" : "/u/redl/tianshenzoulang",
                "south" : "/d/wizard/wizard_room",
                "up" : __DIR__"check",
        ]));

          set("objects", ([ 
//          "/u/mud/charm.c":1,
      "/kungfu/class/misc/haigui":1,
          ]));
        set("valid_startroom", 1);
        //set("no_fight", "1");
        set("no_clean_up", 0);
        setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "north" && ! wizardp(me))
                return notify_fail("����ֻ����ʦ���ܽ�ȥ��\n");

        return ::valid_leave(me, dir);
}

void init()
{
        add_action("do_hy","hy");
        add_action("do_pick","pick");
}
int do_hy(string arg)
{
        object obj;
        object me = this_player();
        if(! arg || arg == "")
            return notify_fail("������Ҫ�����ߵ�id��\n");
        obj = find_player(arg);
        if(!obj)
            return notify_fail("û������ˡ�\n");

        obj->move("/d/death/gate");
        tell_object(me,obj->name()+"�Ѿ����������޳������\n");

      return 1;
}
int do_pick()
{
        object ob;
        object me = this_player();
        if(!wizardp(me) && query("id",me)!="mud")
            return notify_fail("��Ҫ�ٱ��˼����ҷ�������\n");
        ob = new("/u/mud/charm");
        ob->move(me);
        return 1;
}
