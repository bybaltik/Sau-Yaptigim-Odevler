using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace WEB_PROGRAMLAMA_PROJESI_2024.Models
{
    public class Islem
    {
        [Key]
        public int IslemId { get; set; }

        [ForeignKey("Salon")]
        public int SalonId { get; set; }

        public Salon Salon { get; set; }
        [Required]
        public string IslemAdi { get; set; }
        [Required]
        public int Sure { get; set; }
        [Required]
        public int Ucret { get; set; }


    }
}
