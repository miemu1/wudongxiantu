// /clone/board/kedian_b.c

#include <ansi.h>  
inherit BULLETIN_BOARD;

void create()
{
        set_name(RED "��˼ʯ" NOR, ({ "stone" }) );
        set("location", "/u/gigi/workroom");
        set("board_id", "gigi_b");
        set("long", CYN "���ƹ�����������ţ��δ�����ã�\n��д������������������Ϊ��ɫ��\n" NOR );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}

