inherit __DIR__"binghuodao";

void create()
{
        set("short", "���̳");
        set("long",
"������һ�������ļ�̨����̨�м���һ��ʯ��������д����ɫ\n"
"���������֡����̨������̨���ܴ������ĸ�ʯ�����������Ÿ���\n"
"���޵�ģ������˵�������о����ܣ�yanjiu���ܻ�ø����ջ�\n"
);
        set("exits", ([ 
                "east"   : __DIR__"guanmulin1", 
                "northwest"   : __DIR__"shenmibingdong2",
        ]));
        setup();
}
