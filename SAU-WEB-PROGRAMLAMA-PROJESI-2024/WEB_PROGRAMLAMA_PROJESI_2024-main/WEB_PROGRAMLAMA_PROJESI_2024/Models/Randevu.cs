using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace WEB_PROGRAMLAMA_PROJESI_2024.Models
{
    public class Randevu
    {

        [Key]
        public int RandevuId { get; set; }

        [ForeignKey("Musteri")]
        public int MusteriId { get; set; }

        public Musteri Musteri { get; set; }

        [ForeignKey("Calisan")]
        public int CalisanId { get; set; }

        public Calisan Calisan { get; set; }

        [ForeignKey("Islem")]
        public int IslemId { get; set; }

        public Islem Islem { get; set; }
        [Required]
        public DateTime Tarih { get; set; }
        [Required]
        public string SaatAraligi { get; set; }

        public bool Onay { get; set; }





    }
}
