// This program is a part of NT MudLIB
// �䶯��;

#include <ansi.h>

#define DEBOOKS "�䶯��;"

// ���¿�ʼʱ���õľ�����
string *BookMsg = ({
        "��ʱ����֮�У�������а֮�У������Ż�֮�����֡��䵱����ǡ�������ڼ������ħ�̣�������̣�ԩԩ�౨���Ĳ�������",
        "������������һ�壬ʵ���١���ɽ����������Ұ�Ĳ����������̲��������ưԽ���������������ݣ�����������ţ�������ɽ������������֮λ��",
        "����Ⱥԭ�����ڣ������������ز���ͣ���Ⱥ�ʱ��ŵ�������ܻ��������֮ʿ������㱻�ܻ�",
        "����֮��������һ����˵���ּ��洫�ġ���а�������������޵�֮�书��˭�����ɽ������޵У�",
        "������Զͼ����ʮ��·��а�����������֣����������ھ֣��䶯��;���۳����¡�",
        "Զͼ�����������ܣ��ķ����������а���ף�������� ����",
        "��а����֮������������֮�����ɴ�������Ļ��",
});

mapping book_list = ([

        "1"     :    ([ "��ǰ�½�" : "��һ��",
                        "��ǰ����" : "·����ƽ",
                        "��������" : "����ɵ�������һ���������ӣ���·����ƽ���ε�������",
                        "loadboss" : "qcdz.data",  // ��������������boss,���븱��ս��
                        
                        //"����״̬" : 0,
                        //"������" : "1",
                        
                        "�¸�����" : "5", ]),
        "5"     :    ([ "��ǰ�½�" : "��һ��",
                        "��ǰ����" : "�������",
                        "��������" : "����ɵ��Ӵ����˰��֣���˵�е�������٣��������㲻�ò������ˡ�",
                        "�¸�����" : "10", ]),
]);

mapping query_book_list(string n)
{
        if( undefinedp(book_list[n]) ) return 0;
        return book_list[n];
}

// ���� /cmds/usr/skybook.c���ã���ʼ��������
void startbook(object me, string sBook)
{
        string sQuest; // ��ǰ������
        string sZhangjie; // ��ǰ�½�
        object ob, ob2;

        sZhangjie = me->query("skybook14/" + sBook + "/��ǰ�½�");
        sQuest = me->query("skybook14/" + sBook + "/������"); // ��ʾ��û����ɵ�������
        

        if (sQuest == "1")
        {
                DIALOG_D->start_dialog4(this_object(), me, sBookMsg, 0, 1);
                return;
        }
        
        
        FUBEN_D->move_all_invalid_user(me);
        
        move_to_room(me, sQuest);

        return;

}

// ����ȫ��ͨ�أ�����
void endskybook(object me)
{

        // ֪ͨ�������˸�����
        tell_object(me, BLINK + HIY "\n��ϲ�㣡�ɹ�ͨ�ء�" + DEBOOKS + "�����飡\n\n" NOR);
        
        // �㲥ȫ��
        CHANNEL_D->do_channel(this_object(),"rumor", "��˵" + HIY + me->query("name")  + "(" + me->query("id") + ")" HIM "���ء�" + DEBOOKS + "������ɹ���\n");
                
        log_file("ͨ������", me->query("id") + " at " + ctime(time()) + " ͨ�� " + DEBOOKS  + "\n" );
                
        // �ۻ�����ɴ���
        me->add("skybook14/option/" + DEBOOKS + "/completed_times", 1);
        
        // ����ͨ�ع̶�����
        GIFT_D->delay_bonus(me,
                ([ "exp"      : 5000000,
                   "pot"      : 5000000,
                   "mar"      : 5000000,
                   "prompt"   : "����ͨ�ء�" +  DEBOOKS + "�������" ]), 999);  

        // ����ͨ���������
        SUICONG_D->give_end_gift(me, DEBOOKS, me->query("skybook14/" + DEBOOKS + "/�Ѷ�"));

        return;
        
}
