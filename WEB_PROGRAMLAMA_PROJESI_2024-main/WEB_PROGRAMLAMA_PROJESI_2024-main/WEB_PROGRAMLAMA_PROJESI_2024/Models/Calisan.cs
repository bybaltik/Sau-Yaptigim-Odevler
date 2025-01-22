using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace WEB_PROGRAMLAMA_PROJESI_2024.Models
{
    public class Calisan
    {

        [Key]
        public int CalisanId { get; set; }

        [ForeignKey("Islem")]
        public int IslemId { get; set; }

        public Islem Islem { get; set; }

        [ForeignKey("Salon")]
        public int SalonId { get; set; }

        public Salon Salon { get; set; }

        [ForeignKey("Rol")]
        public int RolId { get; set; }

        public Rol Rol { get; set; }
        [Required]
        public string AdSoyad { get; set; }

        // Yeni eklenen alanlar
        [Required]
        [StringLength(50)] // Kullanıcı adı için maksimum karakter sınırı
        public string KullaniciAdi { get; set; }

        [Required]
        [StringLength(100)] // Şifre için maksimum karakter sınırı
        public string Sifre { get; set; }
    }
}
