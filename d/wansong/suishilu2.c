// This program is a part of NITAN MudLIB

inherit ROOM;

void create()
{
        set("short", "��ʯС·"); 
        set("long", @LONG
������ʯС·�������ǡ��������������ˣ������Ǹ�����������
·����������̦��һ�����ľͻ���������಻֪����Ұ�����õ�Ҳï
ʢ��������ɢ����һ�����µĻ��㡣�����ż������һ������Ľ�
����һ̧ͷ�����Կ��������������״��������ӥ״�ķ��ݸ߸߷���
����������С�
LONG );
        set("outdoors", "wansong");
        set("type", "road");
        set("exits",([
                "east":__DIR__"fuguitin",
                "west":__DIR__"wuzhuxuan",
        ]) ); 
        set("objects" , ([
                __DIR__"obj/flower" : 1,
        ]));
        set("coor/x",-600);
        set("coor/y",220);
        set("coor/z",80);
        setup();
        replace_program(ROOM);
}    
