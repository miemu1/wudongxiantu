// ���ϵͳ��������14����籾

#pragma optimize
#pragma save_binary

#include <ansi.h>

inherit F_DBASE;

#define MEMBER_D           "/adm/daemons/memberd"
#define SUICONG_PATH       "SUICONG_LIST_TEST"
#define SUICONG_MAX_LEVEL  10
// ��ӻ��������ֳɱ���
#define SLINE              "=--------------------------------------------------------------------------------------------------------------------="

// ���������Ҫ����Ϊֵ
mapping SUICONG_LEVELUP = ([
"1" : 5000000,
"2" : 6000000,
"3" : 7000000,
"4" : 8000000,
"5" : 9000000,
"6" : 10000000,
"7" : 11000000,
"8" : 12000000,
"9" : 13000000,
"10": 2000000000,
]);


// ÿ�������� �ɻ�ȡ�� ����б�
mapping SUICONG_LIST = ([
        "�ɺ��⴫"    : ({"������", "���", "���˷�","Ԭ����","���ũ","�̱���","������","������","�޳�����","������",}),

        "ѩɽ�ɺ�"    : ({"������", "������", "ƽ����","��ڤ��","�������","�̽���","���Գ�","��ϣ��",   }),
        
        "���Ǿ�"      : ({"����", "�ݷ�", "���Ĳ�","����˼","÷����","ˮ��","Ѫ������","����",  }),
        
        "�����˲�"    : ({"����", "������", "������","������","����","��Զɽ","��̹֮","���հ��Ǵ�","����", "������", 
                          "��ɽͯ��",  "����ˮ",  "���Ǻ�",  "������",  "Ľ�ݲ�",  "Ľ�ݸ�",  
        }),

        "���Ӣ�۴�"  : ({"����", "����", "��ҩʦ","������","�","�����߹�","���߹�","ȫ������","�ܲ�ͨ","һ�ƴ�ʦ", "ɵ��", "��Х��", 
                          "÷����","�����","��ǧ��","��ǧ��","ŷ����","ŷ����","�ƺ��Ĺ�", 
        }),

        "����Х����"  : ({"������", "�߶�����", "�Ϲٺ�","����","����","��³��","��ҿ�",  }),  

        "¹����"      : ({"����", "ΤС��","Τ����","������","������","��ԲԲ","������","�½���","éʮ��",  
                          "��ͷ��", "��ͷ��", "�鰲ͨ","����",
                          "˫��", "����", "��������","����","����","����","�彣��",
        }),     

        "�䶯��;"    : ({"�������", "ľ�߷�", "������","�Բ���","�����","������","ƽһָ","��������","�ɲ���","�������",   
                          "������", "����", "��ӯӯ","�ҹ�����","����ɺ","��ƽ֮","�����","����Ⱥ","������","Ī��", "������",
                          "������", "÷ׯ�Ľ�", 
        }),

        "�齣����¼"  : ({"����", "�¼���","�԰�ɽ", "��̩��", "�޳�����","��ά��","������",
        }),

        "�������"    : ({"С��Ů", "��Ĭ��", "����","�ž���","��Զ��ʦ","�ֳ�Ӣ","������","���ַ���",
                          "���", "�ر����","½��˫","��ܽ",
        }),

        "������"      : ({"ľ����", "������", "����","������","������","ʯ����","���Ʒ���ʹ",
        }),

        "����������"  : ({"ΤһЦ", "������ɢ��", "������","���˿","лѷ","������","�����","���","�䵱����","������",   
                          "����ţ", "����", "����","����","���ʦ̫","���޼�","������", 
        }),

        "��Ѫ��"      : ({"�κ�ҩ", "������", "Ԭ��־","����","�����","����","�����", "ľɣ����",  "������",
        }),

        "ԧ�쵶"      : ({"��ң��", "Ԭ����", "��һ��","����Ӱ","������","׿����",
        }),
]);

// ��Ӧ��ͬ���������������,�����Ѷ����Ϊ1�����Ϊ5
// ����Ч����:�ָ��1λ�������� set_temp()�е�·����2λ�����ʼ1����ӵ�ֵ��3λ����ÿ���������ӵ�ֵ
//"����", "�ݷ�", "���Ĳ�","����","����˼","÷����","ˮ��","Ѫ������","����",
mapping SUICONG_LIST2 = ([

        "����"      : ([ "��������":"���Ǿ�", "�����Ѷ�":2, "����Ч��":"SKBSUICONG/jingli_limit:10:10", "Ч������": "���Ӿ�������10%��100%��ÿ������10%"     ]),
        "����"      : ([ "��������":"���Ǿ�", "�����Ѷ�":1, "����Ч��":"SKBSUICONG/armor_add:10:10", "Ч������": "���ӷ���ֵ10%��100%��ÿ������10%"     ]),
        "ˮ��"      : ([ "��������":"���Ǿ�", "�����Ѷ�":2, "����Ч��":"SKBSUICONG/wound:1:1", "Ч������": "������Ѫ�����˺�1%��10%��ÿ������1%"     ]),
        "÷����"    : ([ "��������":"���Ǿ�", "�����Ѷ�":3, "����Ч��":"SKBSUICONG/pot_add:1:1", "Ч������": "ɱ��Ǳ�ܼӳ�1%��10%��ÿ������1%"     ]),
        "Ѫ������"  : ([ "��������":"���Ǿ�", "�����Ѷ�":3, "����Ч��":"SKBSUICONG/xuedao-dafa:1:1", "Ч������": "Ѫ��������ϵ������+6��15��ÿ��+1��Ѫ���󷨾����˺����������"     ]),
        "����˼"    : ([ "��������":"���Ǿ�", "�����Ѷ�":4, "����Ч��":"SKBSUICONG/armor_dec:2:2", "Ч������": "ÿ������˺������ӶԷ�������2%��20%��ÿ������2%"     ]),
        "�ݷ�"      : ([ "��������":"���Ǿ�", "�����Ѷ�":2, "����Ч��":"SKBSUICONG/hp_add:2:2", "Ч������": "��Ѫ��������2%��20%��ÿ������2%"     ]),
        "���Ĳ�"    : ([ "��������":"���Ǿ�", "�����Ѷ�":1, "����Ч��":"SKBSUICONG/int_add:1:1", "Ч������": "��������+1��10��ÿ��+1"     ]),
        "����"      : ([ "��������":"���Ǿ�", "�����Ѷ�":5, "����Ч��":"SKBSUICONG/shenzhao-jing:1:1", "Ч������": "���վ�����ϵ������+1��10��ÿ��+1�����վ������˺����������"     ]),
]);

// ÿ������һ��������ӣ������Ը���
mapping SUICONG_LIST3 = ([
        "�ɺ��⴫"    : "����",

        "ѩɽ�ɺ�"    : "��һ��",
        
        "���Ǿ�"      : "����",
        
        "�����˲�"    : "ɨ��ɮ",

        "���Ӣ�۴�"  : "����",

        "����Х����"  : "�߲�����",

        "¹����"      : "�������",

        "�䶯��;"    : "����̫��",

        "�齣����¼"  : "������",

        "�������"    : "�������", 

        "������"      : "л�̿�",
        
        "����������"  : "��ɽ",

        "��Ѫ��"      : "������",

        "ԧ�쵶"      : "���л�",

]);


/* �������� */
int need_exp(string sName, string nLevel);

// ���ر������·�����ַ���
string get_path(){return SUICONG_PATH;}

// ����������ȼ�
int get_max_level(string sName){return SUICONG_MAX_LEVEL;}

// ���㵱ǰ��������������Ϊֵ������Ѷ�ϵ����ԭ�л�����ÿ���Ѷ�ϵ������25%������Ϊ
int need_exp(string sName, int nLevel)
{
        int nDiff, nExp;
        mapping mSuicongInfo;
        
        mSuicongInfo = SUICONG_LIST2[sName];
        nDiff = mSuicongInfo["�����Ѷ�"];
        
        nExp = SUICONG_LEVELUP[sprintf("%d",nLevel)];
        
        nExp = nExp + nExp / 100 * (nDiff*25);
        
        return nExp;
}

// �鿴ָ����ӵ���ϸ����
int show_suicong_target(object me, string sName)
{
        string sBook, sSkill, sMsg;
        int nDiff, nExp, nNeedExp;
        string *keys_suicong_list2;
        mapping mSuicongInfo, mySuicongInfo;
        
        keys_suicong_list2 = keys(SUICONG_LIST2);
        if (member_array(sName, keys_suicong_list2) == -1)
                return notify_fail("û�������ӿɲ鿴��\n");
                
        mSuicongInfo = SUICONG_LIST2[sName];
        
        sBook = mSuicongInfo["��������"];
        sSkill = mSuicongInfo["Ч������"];
        nDiff = mSuicongInfo["�����Ѷ�"];
        
        mySuicongInfo = me->query(SUICONG_PATH + "/" + sBook + "/" + sName);
        
        sMsg = HIC "�鿴��ӡ�" + HIY + sName + HIC "����ϸ����\n" NOR;
        sMsg+= SLINE + "\n";
        
        sMsg+= "�������飺��" + sBook + "��\n" +
               "�����Ѷȣ�" + sprintf("%d", nDiff) + "��ϵ��Խ������Խ����\n" + 
               "��ǰ�ȼ���" + (mapp(mySuicongInfo) ? "Lv" + sprintf("%d", mySuicongInfo["level"]) : "δ���") + "\n" + 
               ((mapp(mySuicongInfo) && mySuicongInfo["level"] >= SUICONG_MAX_LEVEL) ? "������Ϊ��" HIG "������" NOR:
               "������Ϊ��" + (mapp(mySuicongInfo) ? sprintf("%d/%d", mySuicongInfo["exp"], need_exp(sName,  mySuicongInfo["level"])) : "δ���") +
                              (mapp(mySuicongInfo) ? "(" + sprintf("%.1f", mySuicongInfo["exp"] * 100.0/need_exp(sName,  mySuicongInfo["level"]) ) + "%)":"")) + "\n"+
               "����Ч����" + HIG +sSkill + "\n" NOR;
        sMsg+= SLINE + "\n";
        sMsg+= HIY "ʹ��ָ��" HIM "suicong sum " + sName + HIY "���ٻ�����ӳ���\n" NOR;       

        write(sMsg);
        
        return 1;
}

// ��ȡ��ӵĵȼ�
public int GetLevel(object me, string sName)
{
        mapping mSuicongInfo, mySuicongInfo;
        string sBook;
        
                
        mSuicongInfo = SUICONG_LIST2[sName];
        
        sBook = mSuicongInfo["��������"];
                
        mySuicongInfo = me->query(SUICONG_PATH + "/" + sBook + "/" + sName);
        
        if (! mapp(mySuicongInfo))return 0;
        
        return mySuicongInfo["level"];  
}

// �޸���ӵȼ�
public int AddLevel(object me, string sName, int nLevel)
{
        mapping mSuicongInfo, mySuicongInfo;
        string sBook;
        
                
        mSuicongInfo = SUICONG_LIST2[sName];
        
        sBook = mSuicongInfo["��������"];
                
        mySuicongInfo = me->query(SUICONG_PATH + "/" + sBook + "/" + sName);
        
        if (! mapp(mySuicongInfo))return 0;
        
        me->add(SUICONG_PATH + "/" + sBook + "/" + sName + "/level",nLevel );
        
        return 1;
}

// ��ȡ�����Ϊ
public int GetExp(object me, string sName)
{
        mapping mSuicongInfo, mySuicongInfo;
        string sBook;

        mSuicongInfo = SUICONG_LIST2[sName];
        
        sBook = mSuicongInfo["��������"];
                
        mySuicongInfo = me->query(SUICONG_PATH + "/" + sBook + "/" + sName);
        
        if (! mapp(mySuicongInfo))return 0;
        
        return mySuicongInfo["exp"];    
}

// �޸������Ϊ
public int AddExp(object me, string sName, int nExp)
{
        mapping mSuicongInfo, mySuicongInfo;
        string sBook;
        
                
        mSuicongInfo = SUICONG_LIST2[sName];
        
        sBook = mSuicongInfo["��������"];
                
        mySuicongInfo = me->query(SUICONG_PATH + "/" + sBook + "/" + sName);
        
        if (! mapp(mySuicongInfo))return 0;
        
        me->add(SUICONG_PATH + "/" + sBook + "/" + sName + "/exp",nExp );
        
        return 1;
}


// �鿴����б�
int show_suicong(object me)
{
        int i,j,k,z;
        string *sBook, sSuicong, *sList;
        string sMsg;
        mapping mSuicongInfo;
        
        if (time() - me->query_temp("last_show_suicong") < 10)
                return notify_fail("10����ֻ�ܲ�ѯһ����ӣ�\n");
        
        me->set_temp("last_show_suicong", time());
        
        sBook = keys(SUICONG_LIST);
        sMsg = HIC "��ʮ��������ӡ������������Ⱥ�\n" NOR;
        k = 0; // ���ܹ����������
        z = 0; // �ܹ����Ŷ��������
                
        for (i = 0;i < sizeof(sBook);i ++)
        {
                sMsg+= SLINE + "\n";
                
                // �Ƿ����˳������           
                if (! me->query(SUICONG_PATH + "/" + sBook[i] + "/" + SUICONG_LIST3[sBook[i]]))
                        sMsg += sprintf("%s��%s��\n", HIY "��" + sBook[i] + "��", "������ӣ�" + NOR + WHT + SUICONG_LIST3[sBook[i]]+ HIY);
                else
                {
                        sMsg += sprintf("%s��%s��\n", HIY "��" + sBook[i] + "��", "������ӣ�" + NOR + HIG + SUICONG_LIST3[sBook[i]] + 
                                "��Lv" + sprintf("%d", me->query(SUICONG_PATH + "/" + sBook[i] + "/" + SUICONG_LIST3[sBook[i]] + "/level")) + "��" HIY );
                        k += 1;
                }
                
                sList = SUICONG_LIST[sBook[i]];
                
                for (j = 0; j < sizeof(sList); j ++)
                {
                        z += 1;
                        mSuicongInfo = me->query(SUICONG_PATH + "/" + sBook[i] + "/" + sList[j]);
                        if (! mSuicongInfo)
                        {
                                sMsg += sprintf( NOR + WHT "%-18s" NOR, sList[j]);                              
                        }
                        else
                        {
                                sMsg += sprintf(HIG "%-18s" NOR, sList[j]+ "��Lv" + sprintf("%d", mSuicongInfo["level"]) + "��"   );
                                k += 1;
                        }
                        
                        if ((j+1)%6 == 0 && j != 0 && (j+1) != sizeof(sList))
                        {
                                sMsg += "\n";
                        }
                }
                sMsg += "\n";           
        }
        sMsg+=  SLINE + "\n";
        sMsg += HIG "��ɫ�������Ѿ���ȡ�����  " NOR + WHT "��ɫ����û�л�ȡ�����   " + 
                HIY "�㵱ǰ������" + sprintf(HIR "%d/%d" HIY, k,z+14) + "��\n" NOR ;
        
        write(sMsg);
        
        return 1;
}

// ����ٻ�
int summon_suicong(object me, string sName)
{
        mapping mSuicongInfo, mySuicongInfo;
        string sBook, *keys_suicong_list2;
        string sPerform, sPath;
        int nLevel, nInit, nAdd;
        
        keys_suicong_list2 = keys(SUICONG_LIST2);
        if (member_array(sName, keys_suicong_list2) == -1)
                return notify_fail("û�������ӣ�\n");

        mSuicongInfo = SUICONG_LIST2[sName];

        sBook = mSuicongInfo["��������"];

        mySuicongInfo = me->query(SUICONG_PATH + "/" + sBook + "/" + sName);
        
        if (! mapp(mySuicongInfo))return notify_fail("�㻹û�л��" + HIG + sName + NOR "�����" HIG + sBook + NOR "�����л�ȡ��\n");
        
        // ��ɾ�������ٻ������
        me->delete_temp(SUICONG_PATH + "/SUICONG");    // ɾ����ǰ�ٻ������
        me->delete_temp("SKBSUICONG"); // ɾ����ӵ���Ч�ӳ�
        
        // ��ע��ǰ�ٻ������
        me->set_temp(SUICONG_PATH + "/SUICONG", sName);
        
        nLevel = mySuicongInfo["level"];
        
        // �����������Ч��   ����Ч��":"SKBSUICONG/shenzhao-jing:1:10
        sPerform = mSuicongInfo["����Ч��"];
        sscanf(sPerform, "%s:%d:%d", sPath, nInit, nAdd);
        me->set_temp(sPath, nInit + (nLevel-1)*nAdd); // ��ʼnInit,ÿ��+nAdd

        message_vision(HIG "$N�ٻ���" HIY + sName + "\n" NOR, me);
        
        return 1;
}

// ���ص�ǰ�ٻ�����ӵ�����
string get_sum(object me)
{
        string sName;
        
        sName = me->query_temp(SUICONG_PATH + "/SUICONG");
        
        if (! sName)return "";
        
        return sName;   
}

// �������
int hide_suicong(object me)
{
        string sName;
        
        sName = me->query_temp(SUICONG_PATH + "/SUICONG");
        
        if (! sName)return notify_fail("�㲢û���ٻ���ӣ������ջأ�\n");
        
        message_vision(HIG "$N��" HIY + sName + HIG "�ջء�\n" NOR, me);
        
        me->delete_temp(SUICONG_PATH + "/SUICONG");
        me->delete_temp("SKBSUICONG"); // ɾ����ӵ���Ч�ӳ�
        
        return 1;
}

// ���һ�����
int give_suicong(object me, string sName)
{
        mapping mSuicongInfo, mySuicongInfo;
        string sBook, *keys_suicong_list2;

        keys_suicong_list2 = keys(SUICONG_LIST2);
        if (member_array(sName, keys_suicong_list2) == -1)
                return notify_fail("û�������ӣ�\n");

        mSuicongInfo = SUICONG_LIST2[sName];

        sBook = mSuicongInfo["��������"];

        mySuicongInfo = me->query(SUICONG_PATH + "/" + sBook + "/" + sName);
        
        // ����Ѿ��������������
        if (mapp(mySuicongInfo))return 0;
        
        // ������Ӳ���ʼ��
        me->set(SUICONG_PATH + "/" + sBook + "/" + sName + "/level", 1);
        me->set(SUICONG_PATH + "/" + sBook + "/" + sName + "/exp", 100);

        return 1;
}


// �ⲿ���ã���ӻ����Ϊ
public void GiveExp(object me, int exp)
{
        string sName;
        int nLevel;
        // �����ǰ���ٻ�����û������
        sName = me->query_temp(SUICONG_PATH + "/SUICONG");
        
        if (sizeof(sName))
        {
                nLevel = GetLevel(me, sName);
                if (nLevel >= SUICONG_MAX_LEVEL)return;

                AddExp(me, sName, exp);

                // ����ﵽ������Ϊ������
                if (GetExp(me, sName) >= need_exp(sName, nLevel))
                {
                        AddLevel(me, sName, 1);
                        AddExp(me, sName, -1 * need_exp(sName, nLevel));
                        tell_object(me, HIG "������" HIY + sName + HIG "�ȼ�������" HIY + sprintf("%d", nLevel+1) + HIG "����\n" NOR);
                        
                        if (nLevel+1 >= SUICONG_MAX_LEVEL)
                                AddExp(me ,sName, -1 * GetExp(me, sName));
                }
                

        }
}

// ����
public void testgiveexp()
{
        GiveExp(this_player(), 1000000);
}

void create()
{
        seteuid(getuid());    
}


