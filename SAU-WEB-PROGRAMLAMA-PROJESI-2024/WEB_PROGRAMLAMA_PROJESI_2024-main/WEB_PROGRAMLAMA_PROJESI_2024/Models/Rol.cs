using System.ComponentModel.DataAnnotations;

namespace WEB_PROGRAMLAMA_PROJESI_2024.Models
{
    public class Rol
    {
        [Key]
        public int RolId { get; set; }
        [Required]
        public string RolAdi { get; set; }
    }
}
