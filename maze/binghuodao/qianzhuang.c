inherit __DIR__"binghuodao";

void create()
{
        set("short", "����Ǯׯ");
        set("long",
"�����Ǳ��𵺵�Ǯׯ��ר��Ϊ���µ�һ�������ṩǮׯ����\n"
);
        set("exits", ([ 
                "north"   : __DIR__"shadi", 
        ]));
        
        set("no_rideto", 1);         // ���ò������������ط�
        set("no_flyto", 1);          // ���ò��ܴ������ط�����������
        set("binghuo", 1);           // ��ʾ�ڱ���
                
        set("no_fight", 1);     
        set("outdoors", 0);
        
        set("objects", ([
                __DIR__"npc/qianzhuang" : 1,
        ]));
                
        setup();
}
