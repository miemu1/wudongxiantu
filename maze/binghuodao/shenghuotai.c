inherit __DIR__"binghuodao";

void create()
{
        set("short", "ʥ��̨");
        set("long",
"������һ�������ļ�̨����̨�м���һ��ʯ��������д���ʺ�\n"
"���������֡�����̨������̨���ܴ������ĸ�ʯ�����������Ÿ���\n"
"��ֵ�ģ������˵�������о����ܿɻ�ø����о�������\n"
);
        set("exits", ([ 
                "north"   : __DIR__"jitan", 
                "south"   : __DIR__"shenmihuodong",
                "west"    : __DIR__"huoyangu2",
        ]));
        setup();
}
