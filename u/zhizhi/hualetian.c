// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <room.h>
inherit CREATE_CHAT_ROOM;

int is_chat_room() { return 1; }

void create()
{
      set("short","������");
        set("long", @LONG
�����ǧ�꣬���Ұ˰��꣬����һ��ҹ���ֱ仯���졣
LONG );

        set("exits", ([ /* sizeof() == 1 */
              "����":"/u/zhizhi/workroom",
        ]));

        set("valid_startroom", 1);
        set("no_fight", "1");
        set("no_clean_up", 0);
        setup();
     call_other("/clone/board/stone_b","???");
         replace_program(ROOM);
}

