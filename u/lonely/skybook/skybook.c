// skybook.c ʮ�������������ָ��

#include <ansi.h>

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

int main(object me, string arg)
{
        string sBook, msg, sDiff, sJindu, sNandu, ssk;
        int i;
        mixed *mFile;

        if( !arg ) return help(me);
                
        if( arg == "list" )
        {
                msg =  HIY "\n�㷭��ʮ�����飬���ּ������������ݡ�������\n" NOR;
                msg += HIC"----------------------------------------------------------------------------\n" NOR;
                msg +=  sprintf(HIG "%-20s%-20s%-20s%-20s\n" NOR, "����", "�Ѷ�", "��ǰ״̬", "��ǰ�Ѷ�");
                msg += HIC"----------------------------------------------------------------------------\n" NOR;
                
                for( i=0; i<sizeof(skybooks); i++ )
                {
                        sscanf(skybooks[sprintf("%d", i+1)], "%s:%s", sBook, sDiff);
                        // ��ɽ��ȣ������ж��Ƿ񼤻�
                        if( !query("skybook14/" + sBook + "/����", me) )
                        {
                                sJindu = NOR + WHT "δ����" NOR;
                        }
                        else
                        {
                                // �����ˣ��ж��Ƿ��Ѿ���������
                                if( !query("skybook14/" + sBook + "/��ǰ�½�", me) )
                                        sJindu = HIR "�Ѽ���" NOR;
                                else
                                        sJindu = HIG + query("skybook14/" + sBook + "/��ǰ�½�", me) + NOR;
                        }
                        
                        // �������˴��֣�����ʾ����״̬Ϊ���
                        if( query("skybook14/" + sBook + "/��ǰ�½�", me) == "����" )
                                        sJindu = HIY "�����" NOR;

                        sBook = HIG + sBook[0..1] + NOR + sBook[2..(sizeof(sBook)-1)];
                        // ��ȡѡ����Ѷ�
                        sNandu = query("skybook14/" + filter_color(sBook) + "/�Ѷ�", me);
                        
                        if( sNandu == 0 )sNandu = "δ����";

                        sJindu = filter_color(sJindu);
                        

                        if( sJindu == "δ����" )
                        {
                                sJindu = NOR + HIR + sJindu + NOR;
                                sNandu = NOR + HIR + sNandu + NOR;
                        }
                        else if( sJindu == "�����" )
                        {
                                sJindu = NOR + HIY + sJindu + NOR;
                                sNandu = NOR + HIY + sNandu + NOR;
                        }
                        else
                        {
                                sJindu = NOR + HIG + sJindu + NOR;
                                sNandu = NOR + HIG + sNandu + NOR;
                        }
                        
                        msg += sprintf("%-20s%-20s%-20s%-20s\n", sBook, sDiff, sJindu, sNandu);
                }

                msg += HIC"----------------------------------------------------------------------------\n" NOR;
                msg += HIY"skybook cha <������> �ɲ鿴��������\n" NOR;
                msg += HIY"skybook jihuo <������> <������/������/��ʦ��>   �ɼ���\n" NOR;
                msg += HIY"skybook reset <������> ����������\n" NOR;
                msg += HIY"skybook start <������> �ɼ�����������\n" NOR;        
                msg += HIC"----------------------------------------------------------------------------\n" NOR;
                msg += HIG"��ǰʣ�����ˣ�" + 
                        sprintf(HIY "%d/%d��" HIG, query("skybook14/option/luck",me),100) + 
                        "��ÿ����ս���鸱���������ģ�������ֵ\n" NOR;
                msg += HIG"ÿ����Сʱ���������ߣ��ɻָ���������ֵ������ֵ����Ϊ�������㡣\n" NOR;

                write(msg);
                return 1;
        }
        
        if( sscanf(arg, "cha %s", sBook) == 1 )
        {
                if( !query("skybook14/" + sBook + "/����", me) )
                        return notify_fail(sBook + "��δ������� " HIG + "skybook jihuo " + sBook + " <������/������/��ʦ��> " NOR" ����\n");
                        
                if( query("skybook14/" + sBook + "/��ǰ�½�", me) == 0)
                        return notify_fail(sBook + "��δ��ʼ������ " HIG + "skybook start " + sBook + NOR " ��ʼ\n");

                msg = HIY + "\n" + sBook + "����������������ݡ�������\n" NOR;
                msg += HIC"----------------------------------------------------------------\n" NOR;             
                if( query("skybook14/" + sBook + "/��ǰ�½�", me) == "����")
                {
                        msg += HIR + "��"  + sBook + "���Ѿ���ɣ��������¿�������ʹ�� " HIG + "skybook reset " + sBook + HIR " ���ã�\n";
                }
                else
                {
                        msg += HIY "��ǰ�½ڣ�" + query("skybook14/" + sBook + "/��ǰ�½�", me) + "\n" NOR;
                        msg += HIY "����������" HIG + query("skybook14/" + sBook + "/��ǰ����", me) + "\n" NOR;
                        //msg += HIY "�ؿ����ƣ�" HIG + query("skybook14/" + sBook + "/��ǰ����", me) + "\n" NOR;
                        if( wizardp(me) )
                                msg += HIY "�����ţ�" + query("skybook14/" + sBook + "/������", me) +  "\n" NOR;
                        msg += HIY "����״̬��" + (query("skybook14/" + sBook + "/����״̬", me) == 1 ? HIG "�����" NOR: HIC "������" NOR) + "\n" NOR;
                        msg += HIY "��ǰ�Ѷȣ�" + query("skybook14/" + sBook + "/�Ѷ�", me) + "\n" NOR;
                }
                msg += HIC"----------------------------------------------------------------\n" NOR;
                msg += HIY"������ " HIG + "skybook start " + sBook + HIY " ��������������\n\n" NOR;           
                write(msg);
                return 1;
        }
        if( sscanf(arg, "jihuo %s %s", sBook, sNandu) == 2 )
        {
                string *get2kskills, *keys_myskills;
                mapping getmyskills;
                
                if( !wizardp(me) ) return notify_fail("��ʱδ���ţ������ڴ���\n");
                
                if( query("skybook14/" + sBook + "/����", me) )
                        return notify_fail(sBook + "�Ѿ������ˣ�\n");
                
                if( query("yuanshen_level") < 100 )
                        return notify_fail("�㻹û��������Ԫ�񵽲��𾳽磬�޷��������飬����Ԫ��˵���� help yuanshen\n");
                
                
                if( sNandu != "������" && sNandu != "������" && sNandu != "��ʦ��" )
                        return notify_fail("������Ѷ�ѡ��ֻ���� ������������������ʦ���е�һ�����:skybook jihuo �䶯��; ��ʦ��\n");
                
                
                // ��ͬ���鲻ͬ��������
                switch(sBook)
                {
                         case "�䶯��;":
                                
                         if( query("skybook14/" + sBook + "/��������", me) )
                         {
                                if( !query_temp("pending_skybook/" + sBook, me) )
                                {
                                        set_temp("pending_skybook/" + sBook, 1, me);
                                        write(HIG "����" HIY + sBook + HIG "��������" + HIY + 
                                              CHINESE_D->chinese(query("skybook14/" + sBook + "/��������", me)) + HIG +
                                              "�������������ȷ����������һ�θ�ָ�\n" NOR);
                                        
                                        return 1;
                                }
                                
                                delete_temp("pending_skybook/" + sBook, me);
                                
                                // ���ͼ��ܣ���ʼ����
                                me->add_skill(query("skybook14/" + sBook + "/��������", me), -200);
                                
                                set("skybook14/" + sBook + "/����", 1, me);
                                
                                write(BLINK + HIG "\n����" HIY + sBook + HIG "�Ѽ������ skybook start " + sBook + " �������£�\n" NOR);

                                // ��ʼ��
                                set("skybook14/" + sBook + "/��ǰ�½�", "��һ��", me);
                                set("skybook14/" + sBook + "/��ǰ����", "·����ƽ", me);
                                set("skybook14/" + sBook + "/��ǰ����", "���� skybook start " + sBook + " ��������Ļ��!", me);
                                set("skybook14/" + sBook + "/�Ѷ�", sNandu, me);
                                set("skybook14/" + sBook + "/������", "1", me);

                                __FILE__->main(me, "cha " + sBook);

                                log_file("0��������.log", me->query_idname() + "����" + sBook + " ���ͼ��� " + 
                                         query("skybook14/" + sBook + "/��������", me) + " At " + ctime(time()) + "\n");
                                
                                delete("skybook14/" + sBook + "/��������", me);
                                return 1;
                         }

                        // ����1500LV�ļ����������200������û�д���1500�ļ��ܣ����ܼ���
                        getmyskills = me->query_skillc();                       
                        if( !sizeof(getmyskills) ) return notify_fail("�������ܶ�û��ѧ�����봳���飿\n");
                        keys_myskills = keys(getmyskills);
                        get2kskills = ({});
                        for( i=0; i<sizeof(keys_myskills); i++ )
                                if( getmyskills[keys_myskills[i]] >= 1500 )
                                        get2kskills += ({ keys_myskills[i] });

                        if( !sizeof(get2kskills) )
                                return notify_fail("���" + sBook + "������������Ҫһ��ܴﵽ������������\n");

                        set_temp("pending_skybook/" + sBook, 1, me);

                        // ���ѡ��1����Ҫ��ĵļ���
                        ssk = get2kskills[random(sizeof(get2kskills))];
                        if( ssk == "martial-cognize" && random(10) < 7 ) ssk = get2kskills[random(sizeof(get2kskills))];
                                
                        set("skybook14/" + sBook + "/��������", ssk, me);

                        write(HIG "����" HIY + sBook + HIG "��������" + HIY + 
                              CHINESE_D->chinese(query("skybook14/" + sBook + "/��������", me)) + HIG +
                              "�������������ȷ����������һ�θ�ָ�\n" NOR);

                        return 1;
                        break; // up �䶯��;
                        
                        case "ѩɽ�ɺ�" :
                        break;
                default:
                        return notify_fail(sBook + "���鲻���ڻ���δ���ţ�\n");

                }// switch
                
                return 1;
        }

        if( sscanf(arg, "start %s", sBook) == 1 )
        {
                object obtianshu;
                string sTianshu;
                
                if( me->is_fighting() || me->is_busy() )
                        return notify_fail("����æ���أ��������԰ɣ�\n");
                
                if( !query("skybook14/" + sBook + "/����", me) )
                        return notify_fail(sBook + "��δ������� " HIG + "skybook jihuo " + sBook + NOR " <�Ѷ�:������/������/��ʦ��>  ������\n");   

                if( query("skybook14/" + sBook + "/��ǰ�½�") == "����", me)
                        return notify_fail(sBook + "�Ѿ���ɣ��������¿�������ʹ�� " HIG + "skybook reset " + sBook + NOR " ���ã�\n");
                        
                // ��������OB����
                sTianshu = skybook_id[sBook];
                if( !objectp(obtianshu = find_object("/clone/skybook14/" + sTianshu + "/" + sTianshu)))
                        obtianshu = load_object("/clone/skybook14/" + sTianshu + "/" + sTianshu);

                if( !objectp(obtianshu) ) return notify_fail("�������OB��������ϵ���ֵ�ʦ�����Ա����\n");

                // �ж������Ϳ۳�����
                if( query("skybook14/option/luck") < 3 )
                        return notify_fail("��ǰ���˲��㣬�޷���ʼ���鸱������ʹ��ָ��" HIY "ntstore buy luck" NOR "��������ȫ�����۸��ntstore show other����\n");

                addn("skybook14/option/luck", -3, me);
                
                tell_object(me, HIY"\nʣ�����ˣ�" + sprintf("%d/100", query("skybook14/option/luck", me)) + "\n" NOR);

                obtianshu->startbook(me, sBook);

                return 1;
                
        }
        if( sscanf(arg, "reset %s", sBook) == 1 )  // ÿ��������Ҫ�����������
        {
                if( !query("skybook14/" + sBook + "/����", me) )
                        return notify_fail(sBook + "��δ������� " HIG + "skybook jihuo " + sBook + NOR " ����\n");   
                /*
                if( query("skybook14/" + sBook + "/��ǰ�½�", me) != "����" )
                        return notify_fail(sBook + "��δ��ɣ��������ã�\n");   
                */      
                // ������Ҫ����NT
                if( MEMBER_D->db_query_member(me, "money") < 99)
                {
                        return notify_fail("����������Ҫ���� 99 NT�ң���û���㹻��ʣ��NT�ң�\n");
                }
                
                if( !query_temp("pending_reset/" + sBook, me) )
                {
                        write(HIG "����" + HIY + sBook + HIG "��Ҫ���� 99 NT�ң������ȷ����������һ�θ�ָ�\n" NOR);
                        set_temp("pending_reset/" + sBook, 1, me);
                        
                        return 1;
                }

                delete_temp("pending_reset/" + sBook, me);

                // �۳�NT
                MEMBER_D->player_pay(me, 99);

                log_file("0��������.log", me->query_idname() + " ���� " + sBook + " at " + ctime(time()) + "\n");
                
                delete("skybook14/" + sBook, me);
                me->save();

                // ���ú��ð�æ����
                set("skybook14/" + sBook + "/����", 0, me);

                write("����" + sBook + "��ϣ�\n");

                return 1;
        }       
        
        if( wizardp(me) && sscanf(arg, "enddialog %s %d", sBook, i) == 2 )  // ����ָ�������ʦֱ����������Ի�
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

skybook list                                       ���鿴ʮ����������
skybook cha <����������>                           ���鿴��Ӧ����������
skybook jihuo <����������> <������/������/��ʦ��>  �������Ӧ�Ѷȵ�����
skybook start <����������>                         �������ϴ�δ�����������
skybook reset <����������>                         ����������ɺ󣬿������������������һ�θ���������

HELP );
    return 1;
}

