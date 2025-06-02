// ���ϵͳ��������14����籾

#pragma optimize
#pragma save_binary

#include <ansi.h>

inherit F_DBASE;

#define MEMBER_D           "/adm/daemons/memberd"
#define SUICONG_PATH       "SUICONG_LIST_TEST"
#define SUICONG_MAX_LEVEL  10
// ��ӻ��������ֳɱ���
#define SLINE              "=----------------------------------------------------------------------------------------------------------------------------="

// ���������Ҫ����Ϊֵ
int SUICONG_LEVELUP = 100000000;

// ÿ�������� �ɻ�ȡ�� ����б�
mapping SUICONG_LIST = ([
/*
        "�ɺ��⴫"    : ({"������", "���", "���˷�","Ԭ����","���ũ","�̱���","������","������","�޳�����","������",}),

        "ѩɽ�ɺ�"    : ({"������", "������", "ƽ����","��ڤ��","�������","�̽���","���Գ�","��ϣ��",   }),
        
        "���Ǿ�"      : ({"����", "�ݷ�", "���Ĳ�","����˼","÷����","ˮ��","Ѫ������","����",  }),
        
        "�����˲�"    : ({"����", "������", "������","������","����","��Զɽ","��̹֮","���հ��Ǵ�","����", "������", 
                          "��ɽͯ��",  "����ˮ",  "���Ǻ�",  "������",  "Ľ�ݲ�",  "Ľ�ݸ�",  
        }),

        "���Ӣ�۴�"  : ({"����", "����", "��ҩʦ","������","�","�����߹�","���߹�","ȫ������","�ܲ�ͨ","һ�ƴ�ʦ", "ɵ��", "��Х��", 
                                      "÷����","�����","��ǧ��","��ǧ��","ŷ����","ŷ����",
        }),

        "����Х����"  : ({"������", "�߶�����", "�Ϲٺ�","����","����","��³��","��ҿ�",  }),  

        "¹����"      : ({"����", "ΤС��","Τ����","������","������","��ԲԲ","������","�½���","éʮ��",  
                                      "��ͷ��", "��ͷ��", "�鰲ͨ","����",
                                      "˫��", "����", "��������","����","����","����","�彣��",
        }),
*/
        "�䶯��;"    : ({"������������","�����������","������ƽһָ","��������������","��������ӯӯ","�������ҹ�����","��������ƽ֮","����������Ⱥ","������������", "������÷ׯ�Ľ�", 
                                "������������","�����������","������ƽһָ","��������������","��������ӯӯ","�������ҹ�����","��������ƽ֮","����������Ⱥ","������������", "������÷ׯ�Ľ�",
                                                                          "��ʦ��������","��ʦ�������","��ʦ��ƽһָ","��ʦ����������","��ʦ����ӯӯ","��ʦ���ҹ�����","��ʦ����ƽ֮","��ʦ������Ⱥ","��ʦ��������", "��ʦ��÷ׯ�Ľ�",
        }),
/*
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
        */
]);

// ��Ӧ��ͬ���������������,�����Ѷ����Ϊ1�����Ϊ5
// ����Ч����:�ָ��1λ�������� set_temp()�е�·����2λ�����ʼ1����ӵ�ֵ��3λ����ÿ���������ӵ�ֵ
//"����", "�ݷ�", "���Ĳ�","����","����˼","÷����","ˮ��","Ѫ������","����",
mapping SUICONG_LIST2 = ([

        // �䶯��;
        // ������������","�����������","������ƽһָ","��������������","��������ӯӯ","�������ҹ�����","��������ƽ֮","����������Ⱥ","������������", "������÷ׯ�Ľ�
        "��ʦ������̫��"    : ([ "��������":"�䶯��;", "�����Ѷ�":5, "����Ч��":"SKBSUICONG/SFORCE-ALL:5:1", "Ч������": "�����ڹ���ϵ������5%-15%��ÿ��+1%"     ]),

        "������������"      : ([ "��������":"�䶯��;", "�����Ѷ�":3, "����Ч��":"SKBSUICONG/SKILL-dugu-jiujian:5:1",  "Ч������": "���¾Ž��˺��������5%��15%��ÿ��+1%"     ]),
        "�����������"      : ([ "��������":"�䶯��;", "�����Ѷ�":3, "����Ч��":"SKBSUICONG/YANJIU-dugu-jiujian:10:1", "Ч������": "���¾Ž��о�Ч������10%-20%��ÿ��+1%"     ]),
        "������ƽһָ"      : ([ "��������":"�䶯��;", "�����Ѷ�":3, "����Ч��":"SKBSUICONG/LIMIT_jingli:10:1",       "Ч������": "������������10%-20%��ÿ��+1%"     ]),
        "��������������"    : ([ "��������":"�䶯��;", "�����Ѷ�":3, "����Ч��":"SKBSUICONG/SKILL-kuihua-mogong:10:1", "Ч������": "����ħ���˺��������10%��20%��ÿ��+1%"     ]),
        "��������ӯӯ"      : ([ "��������":"�䶯��;", "�����Ѷ�":3, "����Ч��":"SKBSUICONG/JIALI-none:5:1",          "Ч������": "�����������5%-15%��ÿ��+1%"     ]),
        "�������ҹ�����"    : ([ "��������":"�䶯��;", "�����Ѷ�":3, "����Ч��":"SKBSUICONG/COMBAT-busy:10:1", "Ч������": "ս���б�BUSY��Ч�󣬽���10%-20%BUSYʱ�䣬ÿ��+1%"     ]),
  "��������ƽ֮"      : ([ "��������":"�䶯��;", "�����Ѷ�":3, "����Ч��":"SKBSUICONG/SKILL-pixie-jian:10:1", "Ч������": "��а�����˺��������10%-20%��ÿ��+1%"     ]),
  "����������Ⱥ"      : ([ "��������":"�䶯��;", "�����Ѷ�":3, "����Ч��":"SKBSUICONG/SFORCE-zixia-shengong:10:2", "Ч������": "��ϼ���ڹ�ϵ���ӳ�����1%-10%��ÿ��+1%"     ]),     
        "������������"      : ([ "��������":"�䶯��;", "�����Ѷ�":3, "����Ч��":"SKBSUICONG/SKILL-xixing-dafa:10:1", "Ч������": "���Ǵ���ȡ����Ч������10%-20%��ÿ��+1%"     ]),
        "������÷ׯ�Ľ�"    : ([ "��������":"�䶯��;", "�����Ѷ�":3, "����Ч��":"SKBSUICONG/GIFT-experence:5:1", "Ч������": "ս����ά������5%-15%��ÿ��+1%"   ]),

        "������������"      : ([ "��������":"�䶯��;", "�����Ѷ�":4, "����Ч��":"SKBSUICONG/SKILL-dugu-jiujian:20:2",  "Ч������": "���¾Ž��˺��������20%��40%��ÿ��+2%"     ]),
        "�����������"      : ([ "��������":"�䶯��;", "�����Ѷ�":4, "����Ч��":"SKBSUICONG/YANJIU-dugu-jiujian:20:2", "Ч������": "���¾Ž��о�Ч������20%-40%��ÿ��+2%"     ]),
        "������ƽһָ"      : ([ "��������":"�䶯��;", "�����Ѷ�":4, "����Ч��":"SKBSUICONG/LIMIT_jingli:20:2",       "Ч������": "������������20%-40%��ÿ��+2%"     ]),
        "��������������"    : ([ "��������":"�䶯��;", "�����Ѷ�":4, "����Ч��":"SKBSUICONG/SKILL-kuihua-mogong:20:2", "Ч������": "����ħ���˺��������20%��40%��ÿ��+2%"     ]),
        "��������ӯӯ"      : ([ "��������":"�䶯��;", "�����Ѷ�":4, "����Ч��":"SKBSUICONG/JIALI-none:20:1",          "Ч������": "�����������20%-30%��ÿ��+1%"     ]),
        "�������ҹ�����"    : ([ "��������":"�䶯��;", "�����Ѷ�":4, "����Ч��":"SKBSUICONG/COMBAT-busy:20:1", "Ч������": "ս���б�BUSY��Ч�󣬽���20%-30%BUSYʱ�䣬ÿ��+1%"     ]),
  "��������ƽ֮"      : ([ "��������":"�䶯��;", "�����Ѷ�":4, "����Ч��":"SKBSUICONG/SKILL-pixie-jian:20:2", "Ч������": "��а�����˺��������20%-40%��ÿ��+2%"     ]),
  "����������Ⱥ"      : ([ "��������":"�䶯��;", "�����Ѷ�":4, "����Ч��":"SKBSUICONG/SFORCE-zixia-shengong:5:1", "Ч������": "��ϼ���ڹ�ϵ���ӳ�����5%-15%��ÿ��+1%"     ]), 
        "������������"      : ([ "��������":"�䶯��;", "�����Ѷ�":4, "����Ч��":"SKBSUICONG/SKILL-xixing-dafa:20:1", "Ч������": "���Ǵ���ȡ����Ч������20%-30%��ÿ��+1%"     ]),
        "������÷ׯ�Ľ�"    : ([ "��������":"�䶯��;", "�����Ѷ�":4, "����Ч��":"SKBSUICONG/GIFT-experence:10:1", "Ч������": "ս����ά������10%-20%��ÿ��+1%"   ]),

        "��ʦ��������"      : ([ "��������":"�䶯��;", "�����Ѷ�":5, "����Ч��":"SKBSUICONG/SKILL-dugu-jiujian:40:2",  "Ч������": "���¾Ž��˺��������40%��60%��ÿ��+2%"     ]),
        "��ʦ�������"      : ([ "��������":"�䶯��;", "�����Ѷ�":5, "����Ч��":"SKBSUICONG/YANJIU-dugu-jiujian:40:2", "Ч������": "���¾Ž��о�Ч������40%-60%��ÿ��+2%"     ]),
        "��ʦ��ƽһָ"      : ([ "��������":"�䶯��;", "�����Ѷ�":5, "����Ч��":"SKBSUICONG/LIMIT_jingli:40:2",       "Ч������": "������������40%-60%��ÿ��+2%"     ]),
        "��ʦ����������"    : ([ "��������":"�䶯��;", "�����Ѷ�":5, "����Ч��":"SKBSUICONG/SKILL-kuihua-mogong:40:2", "Ч������": "����ħ���˺��������40%��60%��ÿ��+2%"     ]),
        "��ʦ����ӯӯ"      : ([ "��������":"�䶯��;", "�����Ѷ�":5, "����Ч��":"SKBSUICONG/JIALI-none:30:1",          "Ч������": "�����������30%-40%��ÿ��+1%"     ]),
        "��ʦ���ҹ�����"    : ([ "��������":"�䶯��;", "�����Ѷ�":5, "����Ч��":"SKBSUICONG/COMBAT-busy:30:5", "Ч������": "ս���б�BUSY��Ч�󣬽���30%-50%BUSYʱ�䣬ÿ��+2%"     ]),
  "��ʦ����ƽ֮"      : ([ "��������":"�䶯��;", "�����Ѷ�":5, "����Ч��":"SKBSUICONG/SKILL-pixie-jian:40:2", "Ч������": "��а�����˺��������40%-60%��ÿ��+2%"     ]),
  "��ʦ������Ⱥ"      : ([ "��������":"�䶯��;", "�����Ѷ�":5, "����Ч��":"SKBSUICONG/SFORCE-zixia-shengong:15:1", "Ч������": "��ϼ���ڹ�ϵ���ӳ�����15%-25%��ÿ��+1%"     ]),     
        "��ʦ��������"      : ([ "��������":"�䶯��;", "�����Ѷ�":5, "����Ч��":"SKBSUICONG/SKILL-xixing-dafa:40:1", "Ч������": "���Ǵ���ȡ����Ч������40%-50%��ÿ��+1%"     ]),
        "��ʦ��÷ׯ�Ľ�"    : ([ "��������":"�䶯��;", "�����Ѷ�":5, "����Ч��":"SKBSUICONG/GIFT-experence:20:1", "Ч������": "ս����ά������20%-30%��ÿ��+1%"   ]),
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
        
        nExp = SUICONG_LEVELUP;
        
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
                                sMsg += sprintf( NOR + WHT "%-22s" NOR, sList[j]);                              
                        }
                        else
                        {
                                sMsg += sprintf(HIG "%-22s" NOR, sList[j]+ "��Lv" + sprintf("%d", mSuicongInfo["level"]) + "��"   );
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
        
        me->set(SUICONG_PATH + "/LAST_SUM", sName);
        
        return 1;
}

// �Զ��ٻ��ϴ��ٻ������
public void auto_sum(object me)
{
                summon_suicong(me, me->query(SUICONG_PATH + "/LAST_SUM"));
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
                        // Э�������ٻ����
                        hide_suicong(me);
                        summon_suicong(me, sName);
                        
                        if (nLevel+1 >= SUICONG_MAX_LEVEL)
                                AddExp(me ,sName, -1 * GetExp(me, sName));
                }
                

        }
}

// ɸѡ��ӣ�����ǰ׺sArray��ɸѡ,���� ���� ��ʦ
public mixed get_suicong_array(string sBook, string sArray)
{
        string *keys_suicong;
        string *keys_result;
        int i;
        
        keys_suicong = SUICONG_LIST[sBook];
        
        keys_result = ({});
        
        for (i = 0; i < sizeof(keys_suicong); i ++)
        {
                if (strsrch(keys_suicong[i], sArray) != -1)
                {
                        keys_result += ({ keys_suicong[i] });
                }               
        }
        
        return keys_result;

} 


// ����SKYBOOK����������ã�ͨ�غ������һ����ӣ������Ѷ�����ѡ
public void give_end_gift(object me, string sBook, string sNandu)
{
        string sArray, sSupersuicong, sSuicong;
        string *ranlist;
        
        sArray = replace_string(sNandu, "��", "��");
        
        // 5%���ʻ�ó������
        if (random(100) < 5)
        {
                if (give_suicong(me, SUICONG_LIST3[sBook]) == 1)
                {
                        CHANNEL_D->do_channel(this_object(),"rumor", "��˵" + HIY + me->query("name")  + "(" + me->query("id") + ")" HIM "����˳�����ӡ�" +SUICONG_LIST3[sBook] + "��һ����\n");
                        tell_object(me, HIY "��ó�����ӡ�" +SUICONG_LIST3[sBook] + "��\n" NOR);
                }
                else
                {
                                tell_object(me, HIR "����˳�����ӣ��������Ѿ����ˣ��Զ�ת��Ϊ�����Ϊ" + sprintf("%d�㡣\n", SUICONG_LEVELUP / 5));
                                GiveExp(me, SUICONG_LEVELUP / 5);
                }
                        
                return;
        }
        
        // ���������
        ranlist = get_suicong_array(sBook, sArray);
        sSuicong = ranlist[random(sizeof(ranlist))];
        if (give_suicong(me, sSuicong) == 1)
        {
                CHANNEL_D->do_channel(this_object(),"rumor", "��˵" + HIY + me->query("name")  + "(" + me->query("id") + ")" HIM "�������ӡ�" +sSuicong + "��һ����\n");
                tell_object(me, HIY "�����ӡ�" +sSuicong + "��\n" NOR);               
        }
        else
        {
                        tell_object(me, HIR "�������ӡ�" +sSuicong + "�����������Ѿ����ˣ��Զ�ת��Ϊ�����Ϊ" + sprintf("%d�㡣\n", SUICONG_LEVELUP / 10));
                        GiveExp(me, SUICONG_LEVELUP / 10);
        }

        return;
        
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

