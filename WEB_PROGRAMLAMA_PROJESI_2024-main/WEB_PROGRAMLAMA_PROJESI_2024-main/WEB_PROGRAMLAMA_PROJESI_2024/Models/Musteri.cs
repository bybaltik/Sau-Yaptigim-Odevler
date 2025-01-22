using System.ComponentModel.DataAnnotations;

namespace WEB_PROGRAMLAMA_PROJESI_2024.Models
{
    public class Musteri
    {
        [Key]
        public int MusteriId { get; set; }
        [Required]
        public string MusteriAdi { get; set; }
        [Required]
        public string MusteriSifre { get; set; }
        [Required]
        public string Email { get; set; }
        [Required]
        public string Telefon { get; set; }
    }
}
