// This program is a part of NITAN MudLIB

inherit ROOM; 
void create()
{
        set("short", "��ʯС·"); 
        set("long", @LONG
������ʯС·������������ɽׯ�ĺ�Ժ�ˣ������Ǹ�����������
·����������̦��һ�����ľͻ���������಻֪����Ұ�����õ�Ҳï
ʢ��������ɢ����һ�����µĻ��㡣�����ż������һ������Ľ�
����һ̧ͷ�����Կ��������������״��������ӥ״�ķ��ݸ߸߷���
����������С�
LONG );
        set("type","road");
        set("outdoors", "wansong");
        set("exits",([
                "south":__DIR__"fuguitin",
                "northeast":__DIR__"grass3",
                "northwest":__DIR__"grass1",
        ]) );
        set("objects" , ([
                __DIR__"obj/flower" : 1,
        ]));    
        set("coor/x",-590);
        set("coor/y",230);
        set("coor/z",80);
        setup();
        replace_program(ROOM);
} 
