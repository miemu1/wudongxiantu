// skybook.c ʮ�������������ָ��

#include <ansi.h>

#define DB_D          "/adm/daemons/dbd"
#define DIALOG_D      "/adm/daemons/dialogd"
#define SUICONG_D     "/adm/daemons/suicongd"
#define SKYBOOK_D     "/adm/daemons/skybookd"

inherit F_CLEAN_UP;

int help(object me);

mapping skybooks = ([

        "1" : "�ɺ��⴫:�����",
        "2" : "ѩɽ�ɺ�:�����",
        "3" : "���Ǿ�:����",
        "4" : "�����˲�:������",
        "5" : "���Ӣ�۴�:������",
        "6" : "����Х����:����",
        "7" : "¹����:�����",
        "8" : "�䶯��;:������",
        "9" : "�齣����¼:�����",
        "10" : "�������:������",
        "11" : "������:������",
        "12" : "����������:������",
        "13" : "��Ѫ��:������",
        "14" : "ԧ�쵶:�����",
]);

// ���ڶ�Ӧ����Ĺ���OB��ÿ�������Ӧ1������OB
mapping skybook_id = ([
        "�ɺ��⴫"    : "feihuwaizhuan",
        "ѩɽ�ɺ�"    : "xueshanfeihu", 
        "���Ǿ�"      : "lianchengjue", 
        "�����˲�"    : "tianlongbabu",
        "���Ӣ�۴�"  : "shediaoyingxiongzhuan",
        "����Х����"  : "baimaxiaoxifeng",
        "¹����"      : "ludingji",
        "�䶯��;"    : "xiaoaojianghu",
        "�齣����¼"  : "shujianenchoulu",
        "�������"    : "shendiaoxialv", 
        "������"      : "xiakexing",    
        "����������"  : "yitiantulongji",
        "��Ѫ��"      : "bixuejian",
        "ԧ�쵶"      : "yuanyangdao",
]);

void create() 
{
        seteuid(getuid());

}

string Get_Pingjia(int nPoint)
{
        if (nPoint == 1)return "��";
        if (nPoint == 2)return  "���";
        if (nPoint == 3)return "����";
        
        return "δ���";
}

int main(object me, string arg)
{
        string sBook, msg, sDiff, sJindu, sPingjia;
        int i;

        if (! arg)return help(me);
        
        if (arg == "list")
        {
                msg =  HIY "\n�㷭��ʮ�����飬���ּ������������ݡ�������\n" NOR;
                msg += HIC"----------------------------------------------------------------------------\n" NOR;
                msg +=  sprintf(HIG "%-20s%-20s%-20s%-20s\n" NOR, "����", "�Ѷ�", "��ɽ���", "�������");
                msg += HIC"----------------------------------------------------------------------------\n" NOR;
                
                for (i = 0; i < sizeof(skybooks); i ++)
                {
                        sscanf(skybooks[sprintf("%d", i+1)], "%s:%s", sBook, sDiff);
                        // ��ɽ��ȣ������ж��Ƿ񼤻�
                        if (! me->query("skybook14/" + sBook + "/����"))
                        {
                                sJindu = NOR + WHT "δ����" NOR;
                        }
                        else
                        {
                                // �����ˣ��ж��Ƿ��Ѿ���������
                                if (! me->query("skybook14/" + sBook + "/��ǰ�½�"))
                                        sJindu = HIR "�Ѽ���" NOR;
                                else
                                        sJindu = HIG + me->query("skybook14/" + sBook + "/��ǰ�½�") + NOR;
                        }

                        sBook = HIG + sBook[0..1] + NOR + sBook[2..(sizeof(sBook)-1)];
                        // ��ȡ����
                        sPingjia = Get_Pingjia(me->query("skybook14/" + sBook + "/�������"));

                        msg += sprintf("%-36s%-20s%-20s%20s\n", sBook, sDiff, sJindu, sPingjia);
                }

                msg += HIC"----------------------------------------------------------------------------\n" NOR;
                msg += HIY"skybook cha <������> �ɲ鿴��������\n" NOR;
                msg += HIY"skybook jihuo <������> �ɼ���\n" NOR;
                msg += HIY"skybook reset <������> ����������\n" NOR;
                msg += HIY"skybook start <������> �ɼ�����������\n" NOR;                
                write(msg);
                return 1;
        }
        
        if (sscanf(arg, "cha %s", sBook) == 1)
        {
                if (! me->query("skybook14/" + sBook + "/����"))
                        return notify_fail(sBook + "��δ������� " HIG + "skybook jihuo " + sBook + NOR " ����\n");
                        
                if (me->query("skybook14/" + sBook + "/��ǰ�½�") == 0)
                        return notify_fail(sBook + "��δ��ʼ������ " HIG + "skybook start " + sBook + NOR " ��ʼ\n");

                msg = HIY + "\n" + sBook + "����������������ݡ�������\n" NOR;
                msg += HIC"----------------------------------------------------------------\n" NOR;
                msg += HIY "��ǰ�½ڣ�" + me->query("skybook14/" + sBook + "/��ǰ�½�") + "\n" NOR;
                msg += HIY "����������" HIG + me->query("skybook14/" + sBook + "/��ǰ����") + "\n" NOR;
                if (wizardp(me))
                        msg += HIY "�����ţ�" + sprintf("%d", me->query("skybook14/" + sBook + "/������")) +  "\n" NOR;
                msg += HIY "����״̬��" + (me->query("skybook14/" + sBook + "/����״̬") == 1 ? HIG "�����" NOR: HIC "������" NOR) + "\n" NOR;
                msg += HIY "������ۣ�" + (me->query("skybook14/" + sBook + "/��ǰ�½�") != "�����" ? "δ���" : me->query("skybook14/" + sBook + "/�������")) + "\n" NOR;
                msg += HIC"----------------------------------------------------------------\n" NOR;
                msg += HIY"��������ɣ������� skybook start " + sBook + " ����������\n\n" NOR;
                
                write(msg);
                return 1;
        }
        if (sscanf(arg, "jihuo %s", sBook) == 1)
        {
                string *get2kskills, *keys_myskills;
                mapping getmyskills;
                
                if (! wizardp(me))return notify_fail("��ʱδ���ţ������ڴ���\n");
                
                if (me->query("skybook14/" + sBook + "/����"))
                        return notify_fail(sBook + "�Ѿ������ˣ�\n");
                
                if (! me->query("scborn/ok"))
                        return notify_fail("�㻹û��ת���������޷��������飬ת��˵���� help scborn\n");
                
                
                
                // ��ͬ���鲻ͬ��������
                switch(sBook)
                {
                         case "���Ǿ�":
                                
                         if (me->query("skybook14/" + sBook + "/��������"))
                         {
                                if (! me->query_temp("want_jihuo_skybook/" + sBook) )
                                {
                                        me->set_temp("want_jihuo_skybook/" + sBook, 1);
                                        write(HIG "����" HIY + sBook + HIG "��������" + HIY + 
                                              CHINESE_D->chinese(me->query("skybook14/" + sBook + "/��������")) + HIG +
                                              "100�������ȷ����������һ�θ�ָ�\n" NOR);
                                        
                                        return 1;
                                }
                                
                                me->delete_temp("want_jihuo_skybook/" + sBook);
                                
                                // ���ͼ��ܣ���ʼ����
                                me->add_skill(me->query("skybook14/" + sBook + "/��������"), -200);

                                me->delete("skybook14/" + sBook + "/��������");
                                
                                me->set("skybook14/" + sBook + "/����", 1);
                                
                                write(HIG "����" HIY + sBook + HIG "�Ѽ������ skybook start + sBook + �������£�\n" NOR);

                                // ��ʼ��
                                me->set("skybook14/" + sBook + "/��ǰ�½�", "����");
                                me->set("skybook14/" + sBook + "/��ǰ����", "���� skybook start " + sBook + " ��������Ļ��!");
                                me->set("skybook14/" + sBook + "/������", 1);
                                
                                __FILE__->main(me, "cha " + sBook);

                                log_file("0��������.log", me->query("id") + "����" + sBook + " ���ͼ��� " + 
                                         me->query("skybook14/" + sBook + "/��������") + " at " + ctime(time()) + "\n");
                                
                                return 1;
                         }

                         // ����1500LV�ļ����������200������û�д���1500�ļ��ܣ����ܼ���
                         getmyskills = me->query_skills();                       
                         if (! sizeof(getmyskills))return notify_fail("�������ܶ�û��ѧ�����봳���飿\n");
                         keys_myskills = keys(getmyskills);
                         get2kskills = ({});
                         for (i = 0; i < sizeof(keys_myskills); i ++)
                                if (getmyskills[keys_myskills[i]] >= 1500)
                                        get2kskills += ({keys_myskills[i]});

                        if (! sizeof(get2kskills))
                                return notify_fail("�������Ǿ�����������Ҫһ��ܴﵽ1500����\n");

                        me->set_temp("want_jihuo_skybook/" + sBook, 1);

                        // ���ѡ��1����Ҫ��ĵļ���
                        me->set("skybook14/" + sBook + "/��������", get2kskills[random(sizeof(get2kskills))] );

                        write(HIG "����" HIY + sBook + HIG "��������" + HIY + 
                              CHINESE_D->chinese(me->query("skybook14/" + sBook + "/��������")) + HIG +
                              "200�������ȷ����������һ�θ�ָ�\n" NOR);

                        return 1;                       
                        break; // up ���Ǿ�

                        default:
                                return notify_fail(sBook + "���鲻���ڻ���δ���ţ�\n");

                }// switch
                
                return 1;
        }
        if (sscanf(arg, "start %s", sBook) == 1)
        {
                object obtianshu;
                string sTianshu;
                
                if (me->is_fighting() || me->is_busy())
                        return notify_fail("����æ���أ��������԰ɣ�\n");
                
                if (! me->query("skybook14/" + sBook + "/����"))
                        return notify_fail(sBook + "��δ������� " HIG + "skybook jihuo " + sBook + NOR " ����\n");               

                // ��������OB����
                sTianshu = skybook_id[sBook];
                if (! objectp(obtianshu = find_object("/clone/skybook14/" + sTianshu + "/" + sTianshu)))
                        obtianshu = load_object("/clone/skybook14/" + sTianshu + "/" + sTianshu);

                if (! objectp(obtianshu))return notify_fail("�������OB��������ϵ���ֵ�ʦ�����Ա����\n");

                obtianshu->startbook(me, sBook);
                
                return 1;               
                
        }
        if (sscanf(arg, "reset %s", sBook) == 1)  // ÿ��������Ҫ�����������
        {
                if (! me->query("skybook14/" + sBook + "/����"))
                        return notify_fail(sBook + "��δ������� " HIG + "skybook jihuo " + sBook + NOR " ����\n");   

                if (me->query("skybook14/" + sBook + "/��ǰ�½�") != "�����")
                        return notify_fail(sBook + "��δ��ɣ��������ã�\n");   
                
                // ������Ҫ����SCB
                if (DB_D->query_data("yhshop/scb/" + me->query("id")) < 99)
                {
                        return notify_fail("����������Ҫ����99�̳Ǳң���û���㹻��ʣ���̳Ǳң�\n");
                }
                
                if (! me->query_temp("want_reset_tianshu/" + sBook))
                {
                        write(HIG "����" + HIY + sBook + HIG "��Ҫ����99�̳Ǳң������ȷ����������һ�θ�ָ�\n" NOR);
                        me->set_temp("want_reset_tianshu/" + sBook, 1);
                        
                        return 1;
                }
                
                me->delete_temp("want_reset_tianshu/" + sBook);

                // �۳�SCB
                DB_D->set_data("yhshop/scb/" + me->query("id"), DB_D->query_data("yhshop/scb/" + me->query("id"))-99);

                log_file("0��������.log", me->query("id") + " ���� " + sBook + " at " + ctime(time()) + "\n");
                
                me->delete("skybook14/" + sBook);
                me->save();

                // ���ú��ð�æ����
                me->set("skybook14/" + sBook + "/����", 0);

                write("����" + sBook + "��ϣ�\n");

                return 1;
        }       
        if (wizardp(me) && sscanf(arg, "enddialog %s %d", sBook, i) == 2)  // ����ָ�������ʦֱ����������Ի�
        {
                object obroom;
                
                if (! objectp(obroom = find_object("/clone/skybook14/" + sBook + "/" + sBook)))
                        obroom = load_object("/clone/skybook14/" + sBook + "/" + sBook);                

                obroom->dialog_end(me, i);
                return 1;
        }
}

int help(object me)
{
        write(@HELP
ָ���ʽ : skybook

skybook list                 ���鿴ʮ����������
skybook cha <����������>     ���鿴��Ӧ����������
skybook jihuo <����������>   �������Ӧ������
skybook start <����������>   �������ϴ�δ�����������
skybook reset <����������>   ����������ɺ󣬿������������������һ�θ���������

HELP );
    return 1;
}
