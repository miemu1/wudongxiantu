// This program is a part of NITAN MudLIB

inherit ROOM;

void create()
{
        set("short", "����ɽׯ����");
        set("long", @LONG
·����ͷ�������������µġ�����ɽׯ���Ĵ��š�էһ��ȥ����
�����ϵ����̷��ۼ���أ���֪�����Ŷ����ܹ��ɽ�����Ѫ������
������Ϊׯ�����Ǹ����Թ�֮�ˡ���ǰ���Ҹ�����һֻ����ׯ�ϵ�ʯ
ʨ�ӡ�������ϸ�ƣ��������̾������ԭ�������⼣�߰ߣ����ǻҳ���
����Ҳ�Ѱ����룬Ī��֮�����˲���һ�������ĸо���
LONG );
        set("outdoors", "wansong");
        set("type", "street");
        set("exits",([
                "eastdown":__DIR__"shandao2",
                "enter":__DIR__"suishilu1",
        ]) );

        set("coor/x",-590);
        set("coor/y",200);
        set("coor/z",80);
        
        setup();
        
        replace_program(ROOM);
} 

