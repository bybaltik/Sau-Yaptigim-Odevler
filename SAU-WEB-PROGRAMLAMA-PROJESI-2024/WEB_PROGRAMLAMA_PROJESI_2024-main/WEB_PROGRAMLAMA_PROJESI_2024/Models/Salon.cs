using System.ComponentModel.DataAnnotations;

namespace WEB_PROGRAMLAMA_PROJESI_2024.Models
{
    public class Salon
    {
        [Key]
        public int SalonId { get; set; }
        [Required]
        public string SalonAdi { get; set; }
        [Required]
        public string Adres { get; set; }
        [Required]
        public string CalismaSaatleri { get; set; }
    }
}
