inherit __DIR__"binghuodao";

void create()
{
        set("short", "���̳");
        set("long",
"������һ�������ļ�̨����̨�м���һ��ʯ��������д���ʺ�\n"
"���������֡����̨������̨���ܴ������ĸ�ʯ�����������Ÿ���\n"
"�����ģ������˵�����Ｓȡʵս��ᣨjiqu���ܻ�ø����ջ�\n"
);
        set("exits", ([ 
                "east"   : __DIR__"guanmulin2", 
                "southwest"   : __DIR__"shenmihuodong2",
        ]));
        setup();
}
