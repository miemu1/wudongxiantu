// This program is a part of NITAN MudLIB

inherit ROOM;

void create()
{
        set("short", "����԰"); 
        set("long", @LONG
�����������������ܾ��Ǵ���԰��������������ÿ�������°�
����ҹ������ɽׯ�����������Ǳ�����ˣ�һ�����Σ�һ����裬��
�Ǻ��˰������������ϧ�����ɺܾ��Ѿ�û��������ˣ����ǻ�ʱ��
�������ֵ��ǿ�����Ǯ���ƣ��긴һ�꣬����԰�е�����ҲԽ��Խ�١�
LONG );
        set("outdoors", "wansong");
        set("type","forest");
        set("exits",([
                "east":__DIR__"wuzhuxuan",
        ]) );
        set("objects",([
                CLASS_D("mojiao/tieyan") : 1,
                CLASS_D("mojiao/tie-wife") : 1,
        ]));
        set("coor/x",-620);
        set("coor/y",220);
        set("coor/z",80);
        setup();
        setup();
        replace_program(ROOM);
}       
