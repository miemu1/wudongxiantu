// File(/data/room/redl/key.c) of redl's key
// Create by LUBAN written by Doing Lu

#include <ansi.h>

inherit ITEM;

int query_autoload() { return 1; }

void create()
{
        set_name(YEL "��������ҵ�Կ��" NOR, ({ "key", "1 of redl" }));
        set_weight(10);
        set("long", @LONG
һ��������������(redl)��Կ�ס�
����ԭ��Կ�ס�
LONG );
        set("unit", "��");
        set("no_pawn", 1);
        set("no_sell", 1);
        set("no_store", 1);
        set("item_make", 1);
        set("value", 1);
}
