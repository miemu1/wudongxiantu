// This program is a part of NITAN MudLIB

inherit ROOM;

void create()
{
        set("short", "��԰"); 
        set("long", @LONG
�����������ɽׯ�ġ�ʥ�ء���԰��֮��������˵����Ϊ������
������˵�����������ζ�Ŷ��˿����ü�ֻ���ӳ伢��������Ҫ���ǣ�
�Ƴ������ˣ�Ҳ��ժ��������ȥ���ƺȣ�ʱ�����������ԭ������
���������ִ�����ӣ�������ȴ�Ѿ���ժ�ü�����ʣ�޼��ˡ�
LONG );
        set("type","forest");
        set("outdoors", "wansong");
        set("exits",([
                "west":__DIR__"shibanlu2",
        ]) );

        set("objects",([
                CLASS_D("mojiao/yinlong") : 1,
        ]) );
        
        set("coor/x",-570);
        set("coor/y",220);
        set("coor/z",80);
        setup(); 
} 

