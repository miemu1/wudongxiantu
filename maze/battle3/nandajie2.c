inherit ROOM;

void create()
{
        set("short", "�Ͻֹ㳡");
        set("long", @LONG
�������Ͻֹ㳡�ˣ����ڿ������������ģ������Ϊ����������
��һ����Ժ����˵���ǵ�һ���ˡ���ʦʦ����������������ģ�����
������Ц֮�˷�ӵ����������֪�����Է���Ҳ�������Ǹ����ׯ����
�澭Ӫ�ĸ��ֲ�ƥ���ܴ�ٹ����ǵ�������
LONG );
        set("outdoors", "city2");
        set("no_fly",1);

        set("exits", ([
                "north" : __DIR__"center",
                "south" : __DIR__"nandajie1",
        ]));

        set("objects", ([

        ]));

        setup();
        replace_program(ROOM);
}
