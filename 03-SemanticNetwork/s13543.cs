using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3syume
{
    class ikimono //�����N���X
    {
        public bool ikimonoclass; //�����N���X�ł��邱�Ƃ��m���߂郁���o�ϐ�
        public string ikimono_name; //�����̖��O�����郁���o�ϐ�
        public bool kokyuu = true; //�ċz���邩�ǂ������m���߂郁���o�ϐ�
    }

    class tori : ikimono�@//���N���X(�����N���X���p��)
    {
        public string tori_name; //���̎�ނ��i�[���郁���o�ϐ�
        public bool tsubasa = true; //���ɗ������邩���m���߂郁���o�ϐ�
        public string tokugi; //���̓��Z���i�[���郁���o�ϐ�

    }

    class Program
    {
        static void Main(string[] args)
        {
            int select = 0; //�I�������i�[����ϐ�
            tori t1 = new tori(); //�I�u�W�F�N�g�쐬
            
            t1.tori_name = "�I�E��"; //������t�^
            t1.ikimono_name = "��"; //������t�^
            t1.tokugi = "���m�}�l"; //������t�^
            t1.ikimonoclass = true; //������t�^

            Console.WriteLine("�s�����������I��ł�������".ToString()); //�I�������
            Console.WriteLine("1 : �I�[���̓��Z�͉��ł����H".ToString());
            Console.WriteLine("2 : �I�[���͌ċz���邩�H".ToString());
            select = int.Parse(System.Console.ReadLine()); //�I���������

            if (select == 1) {
                Console.WriteLine("�I�[���̓��Z�͉��ł����H".ToString());
                Console.WriteLine("�I�[���̓��Z�� " + t1.tokugi.ToString());
            }
            else if (select == 2)
            {
                Console.WriteLine("�I�[���͌ċz���邩�H".ToString()); //is-a�֌W��p�����ؖ�������
                Console.WriteLine("�܂��I�[���͐������H�@=�@" + t1.ikimonoclass.ToString());
                Console.WriteLine("�����͌ċz�����邩�H�@=�@" + t1.kokyuu.ToString());
                Console.WriteLine("����ăI�[���͌ċz������".ToString()); //is-a�֌W��p�����ؖ��I��
            }
            else 
            {
                Console.WriteLine("�G���[".ToString());
            }
        }
    }
    
}
