inherit __DIR__"binghuodao";

void create()
{
        set("short", "����̨");
        set("long",
"������һ�������ļ�̨����̨�м���һ��ʯ��������д���ʺ�\n"
"���������֡�����̨������̨���ܴ������ĸ�ʯ����������������\n"
"���޵�ģ������˵������ڤ˼��reflect���ܻ�ø����ջ�\n"
);
        set("exits", ([ 
                "west"   : __DIR__"bingfenggu2", 
                "north"   : __DIR__"shenmibingdong",
                "south"   : __DIR__"jitan",
        ]));
        setup();
}
